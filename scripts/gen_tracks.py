#!/usr/bin/env python3
"""
Scans all solution files in problems/ (excluding scratch/ and inbox/),
parses metadata headers, groups by platform, and generates track README
files with solution tables sorted by id.
"""

import os
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
PROBLEMS_DIR = ROOT / "problems"
TRACKS_DIR = ROOT / "tracks"

EXCLUDE_DIRS = {"scratch", "inbox"}

# Maps platform metadata value -> track directory name and display title
PLATFORM_MAP = {
    "lc": ("leetcode", "LeetCode"),
    "cf": ("codeforces", "Codeforces"),
    "tip102": ("codepath_tip102", "CodePath TIP102"),
    "csc2720": ("csc_2720", "CSC 2720"),
}

# For files without metadata, try to detect platform from filename prefix
FILENAME_PREFIX_MAP = {
    "lc-": "lc",
    "cf-": "cf",
    "tip102-": "tip102",
    "csc2720-": "csc2720",
}

# For files where neither metadata nor filename prefix works, check path
PATH_PLATFORM_MAP = {
    "janestreet": ("janestreet", "Jane Street"),
}


def parse_metadata(filepath):
    """Parse the metadata header from a solution file.

    Supports both Python (triple-quote) and C++ (/* ... */) comment blocks.
    Returns a dict with keys: platform, id, name, pattern, tags.
    Returns None if no metadata header is found.
    """
    try:
        with open(filepath, "r", encoding="utf-8", errors="replace") as f:
            content = f.read(2000)  # Only need the header
    except Exception:
        return None

    # Extract the comment block
    header = None
    # Python triple-quote block
    if content.lstrip().startswith('"""'):
        match = re.search(r'"""(.*?)"""', content, re.DOTALL)
        if match:
            header = match.group(1)
    # C++ block comment
    elif content.lstrip().startswith("/*"):
        match = re.search(r'/\*(.*?)\*/', content, re.DOTALL)
        if match:
            header = match.group(1)

    if not header:
        return None

    # Parse key: value pairs from the header
    metadata = {}
    for line in header.splitlines():
        line = line.strip()
        # Match lines like "platform: lc" or "id: 123"
        m = re.match(r'^(\w+)\s*:\s*(.+)$', line)
        if m:
            key = m.group(1).strip()
            value = m.group(2).strip()
            if key in ("platform", "id", "name", "pattern", "tags"):
                metadata[key] = value

    if "platform" in metadata:
        return metadata
    return None


def detect_platform_from_filename(filename):
    """Try to detect platform from the filename prefix."""
    for prefix, platform in FILENAME_PREFIX_MAP.items():
        if filename.startswith(prefix):
            return platform
    return None


def extract_info_from_filename(filename, platform_prefix):
    """Extract id and name from a filename like 'lc-125-valid-palindrome.py'
    or 'tip102-wk3s1-clean-post.py' or 'csc2720-course-order.py'."""
    # Strip extension
    stem = Path(filename).stem

    if platform_prefix in ("lc", "cf"):
        # Pattern: <platform>-<id>-<name-slug>
        m = re.match(r'^(?:lc|cf)-([^-]+)-(.+)$', stem)
        if m:
            return m.group(1), m.group(2)
    elif platform_prefix == "tip102":
        # Pattern: tip102-<rest-is-the-name>
        # The "id" for tip102 is the session identifier like wk3s1
        m = re.match(r'^tip102-(.+)$', stem)
        if m:
            rest = m.group(1)
            # Try to split into week/session id and name
            # e.g. wk3s1-clean-post -> id=wk3s1, name=clean-post
            wk_match = re.match(r'^(wk\d+s?\d*a?)-(.+)$', rest)
            if wk_match:
                return wk_match.group(1), wk_match.group(2)
            else:
                # No week prefix (e.g. tip102-best-time-buy-sell)
                return "", rest
    elif platform_prefix == "csc2720":
        m = re.match(r'^csc2720-(.+)$', stem)
        if m:
            return "", m.group(1)

    return None, None


def get_pattern_from_path(filepath):
    """Extract the pattern (subdirectory path relative to problems/) from a file path."""
    rel = filepath.relative_to(PROBLEMS_DIR)
    # The pattern is everything except the filename
    return str(rel.parent)


def title_case_name(slug):
    """Convert a hyphen-separated slug to title case for display.
    e.g. 'two-sum' -> 'Two Sum'
    """
    if not slug:
        return ""
    # Handle roman numerals and special cases
    words = slug.split("-")
    result = []
    roman_numerals = {"i", "ii", "iii", "iv", "v", "vi", "vii", "viii", "ix", "x"}
    for w in words:
        if w.lower() in roman_numerals and len(w) <= 4:
            result.append(w.upper())
        else:
            result.append(w.capitalize())
    return " ".join(result)


def sort_key_lc(entry):
    """Sort key for LeetCode: numeric id."""
    try:
        return (0, int(entry["id"]), entry["name"])
    except (ValueError, TypeError):
        return (1, 0, entry.get("name", ""))


def sort_key_cf(entry):
    """Sort key for Codeforces: alphanumeric id (e.g. 4A, 69A, 499B).
    Sort by numeric part first, then letter."""
    raw_id = entry.get("id", "")
    m = re.match(r'^(\d+)([A-Za-z]*)$', raw_id)
    if m:
        return (0, int(m.group(1)), m.group(2), entry["name"])
    return (1, 0, raw_id, entry.get("name", ""))


def sort_key_tip102(entry):
    """Sort key for TIP102: by week/session id then name."""
    raw_id = entry.get("id", "")
    # Parse wk<N>s<M> or wk<N>s<M>a
    m = re.match(r'^wk(\d+)s(\d+)(a?)$', raw_id)
    if m:
        return (0, int(m.group(1)), int(m.group(2)), m.group(3), entry["name"])
    # No week prefix
    return (1, 0, 0, "", entry.get("name", ""))


def sort_key_generic(entry):
    """Generic sort: by name."""
    return (entry.get("name", ""),)


def make_relative_link(filepath):
    """Make a relative link from tracks/<track>/README.md to the solution file."""
    rel = filepath.relative_to(PROBLEMS_DIR)
    return f"../../problems/{rel}"


def collect_solutions():
    """Walk the problems directory and collect all solution entries."""
    solutions = {}  # platform -> list of entry dicts

    for dirpath, dirnames, filenames in os.walk(PROBLEMS_DIR):
        dirpath = Path(dirpath)

        # Skip excluded directories
        rel_to_problems = dirpath.relative_to(PROBLEMS_DIR)
        top_level = rel_to_problems.parts[0] if rel_to_problems.parts else ""
        if top_level in EXCLUDE_DIRS:
            continue

        for filename in filenames:
            if not (filename.endswith(".py") or filename.endswith(".cpp")):
                continue

            filepath = dirpath / filename
            pattern = get_pattern_from_path(filepath)

            # Try parsing metadata first
            meta = parse_metadata(filepath)

            if meta and meta.get("platform"):
                platform = meta["platform"]
                entry = {
                    "id": meta.get("id", ""),
                    "name": meta.get("name", ""),
                    "pattern": meta.get("pattern", pattern),
                    "tags": meta.get("tags", ""),
                    "filepath": filepath,
                }
            else:
                # No metadata - try detecting from filename
                platform = detect_platform_from_filename(filename)
                if platform:
                    file_id, file_name = extract_info_from_filename(filename, platform)
                    if file_name is None:
                        continue
                    entry = {
                        "id": file_id or "",
                        "name": file_name,
                        "pattern": pattern,
                        "tags": "",
                        "filepath": filepath,
                    }
                else:
                    # Check path for clues (e.g. janestreet in inbox - but we
                    # skip inbox, so this catches anything else)
                    found = False
                    for path_key, (track_dir, track_title) in PATH_PLATFORM_MAP.items():
                        if path_key in str(filepath):
                            platform = path_key
                            entry = {
                                "id": "",
                                "name": Path(filename).stem,
                                "pattern": pattern,
                                "tags": "",
                                "filepath": filepath,
                            }
                            found = True
                            break
                    if not found:
                        # Skip files we can't categorize (utility files like dijkstras.cpp)
                        continue

            if platform not in solutions:
                solutions[platform] = []
            solutions[platform].append(entry)

    return solutions


def generate_readme(platform, entries):
    """Generate README content for a given platform track."""
    # Determine track info
    if platform in PLATFORM_MAP:
        track_dir, title = PLATFORM_MAP[platform]
    elif platform in PATH_PLATFORM_MAP:
        track_dir, title = PATH_PLATFORM_MAP[platform]
    else:
        return None, None

    # Choose sort function
    if platform == "lc":
        entries.sort(key=sort_key_lc)
    elif platform == "cf":
        entries.sort(key=sort_key_cf)
    elif platform == "tip102":
        entries.sort(key=sort_key_tip102)
    else:
        entries.sort(key=sort_key_generic)

    lines = [
        f"# {title}",
        "",
        "Canonical solutions live in `/problems`.",
        "",
        "| # | Problem | Pattern | Tags |",
        "|---|---------|---------|------|",
    ]

    for entry in entries:
        display_id = entry["id"]
        display_name = title_case_name(entry["name"])
        link = make_relative_link(entry["filepath"])
        pattern = entry.get("pattern", "")
        tags = entry.get("tags", "")

        lines.append(
            f"| {display_id} | [{display_name}]({link}) | {pattern} | {tags} |"
        )

    lines.append("")  # trailing newline
    return track_dir, "\n".join(lines)


def main():
    solutions = collect_solutions()

    for platform, entries in solutions.items():
        result = generate_readme(platform, entries)
        if result is None:
            print(f"  Skipping unknown platform: {platform}")
            continue

        track_dir, content = result
        readme_path = TRACKS_DIR / track_dir / "README.md"

        if not readme_path.parent.exists():
            print(f"  Warning: track directory {readme_path.parent} does not exist, creating it")
            readme_path.parent.mkdir(parents=True, exist_ok=True)

        with open(readme_path, "w", encoding="utf-8") as f:
            f.write(content)

        print(f"  Generated {readme_path} ({len(entries)} solutions)")

    # Report platforms found
    print(f"\nPlatforms found: {', '.join(sorted(solutions.keys()))}")
    print(f"Total solutions: {sum(len(v) for v in solutions.values())}")


if __name__ == "__main__":
    main()
