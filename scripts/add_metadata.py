#!/usr/bin/env python3
"""
Add difficulty: and url: fields to all solution metadata headers in problems/.
Skips files in scratch/ and inbox/, and files without a metadata header.
"""

import os
import re
import sys

PROBLEMS_DIR = os.path.join(
    os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "problems"
)

# LeetCode difficulty mapping
LC_DIFFICULTY = {}

for pid in [
    1,
    9,
    20,
    21,
    67,
    78,
    110,
    121,
    125,
    141,
    150,
    206,
    226,
    242,
    252,
    704,
    733,
    744,
    961,
    1200,
    1266,
    3379,
    3507,
    3637,
    3798,
]:
    LC_DIFFICULTY[str(pid)] = "easy"

for pid in [
    3,
    5,
    19,
    36,
    45,
    54,
    56,
    57,
    59,
    91,
    97,
    134,
    139,
    152,
    213,
    223,
    235,
    238,
    253,
    271,
    286,
    300,
    309,
    329,
    332,
    347,
    362,
    435,
    490,
    566,
    567,
    651,
    678,
    684,
    712,
    763,
    787,
    799,
    846,
    1123,
    1161,
    1292,
    1339,
    1382,
    1390,
    1458,
    1584,
    1653,
    1899,
    1975,
    1984,
    2013,
    3010,
    3047,
    3650,
    3713,
    3714,
    3719,
    3799,
    3800,
]:
    LC_DIFFICULTY[str(pid)] = "medium"

for pid in [10, 72, 84, 85, 115, 269, 312, 499, 743, 778, 3510, 3640, 3651, 3801]:
    LC_DIFFICULTY[str(pid)] = "hard"


def make_lc_url(name):
    """Convert a name field to a LeetCode URL slug."""
    # Replace spaces with hyphens, lowercase, strip trailing/leading whitespace
    slug = name.strip().lower().replace(" ", "-")
    return f"https://leetcode.com/problems/{slug}/"


def make_cf_url(cf_id):
    """Convert a Codeforces ID like '4A' or '2193D' to a URL."""
    # Split into contest number and letter
    match = re.match(r"^(\d+)([A-Za-z]\d?)$", cf_id.strip())
    if match:
        contest = match.group(1)
        letter = match.group(2)
        return f"https://codeforces.com/problemset/problem/{contest}/{letter}"
    return None


def process_file(filepath):
    """Process a single solution file, adding difficulty and url fields."""
    with open(filepath, "r") as f:
        content = f.read()

    # Determine if this is a Python or C++ file
    is_python = filepath.endswith(".py")
    is_cpp = filepath.endswith(".cpp")

    if not (is_python or is_cpp):
        return False

    # Check for metadata header
    if is_python and not content.startswith('"""'):
        return False
    if is_cpp and not content.startswith("/*"):
        return False

    # Check if difficulty: or url: already present in the header
    # Find the header boundary
    if is_python:
        header_end = content.find('"""', 3)
        if header_end == -1:
            return False
        header = content[:header_end]
    else:
        header_end = content.find("*/")
        if header_end == -1:
            return False
        header = content[:header_end]

    # Skip if already has difficulty or url
    if "difficulty:" in header and "url:" in header:
        return False

    # Parse platform, id, and name from header
    platform_match = re.search(r"^platform:\s*(.+)$", header, re.MULTILINE)
    id_match = re.search(r"^id:\s*(.+)$", header, re.MULTILINE)
    name_match = re.search(r"^name:\s*(.+)$", header, re.MULTILINE)

    if not platform_match or not id_match or not name_match:
        return False

    platform = platform_match.group(1).strip()
    prob_id = id_match.group(1).strip()
    name = name_match.group(1).strip()

    # Build the new fields
    difficulty_line = None
    url_line = None

    if platform == "lc":
        diff = LC_DIFFICULTY.get(prob_id)
        if diff:
            difficulty_line = f"difficulty: {diff}"
        else:
            difficulty_line = "difficulty: unknown"
            print(f"  WARNING: Unknown difficulty for LC #{
                  prob_id} in {filepath}")
        url_line = f"url: {make_lc_url(name)}"
    elif platform == "cf":
        cf_url = make_cf_url(prob_id)
        if cf_url:
            url_line = f"url: {cf_url}"
        # Omit difficulty for CF
    else:
        # tip102, csc2720, etc. - skip url, omit difficulty
        return False

    # Insert after the name: line and before pattern: line
    # Find the name line and insert after it
    lines = content.split("\n")
    new_lines = []
    inserted = False

    for i, line in enumerate(lines):
        new_lines.append(line)
        if not inserted and re.match(r"^name:\s", line):
            # Insert difficulty and url after name line
            if difficulty_line and "difficulty:" not in header:
                new_lines.append(difficulty_line)
            if url_line and "url:" not in header:
                new_lines.append(url_line)
            inserted = True

    if not inserted:
        print(f"  WARNING: Could not find name: line in {filepath}")
        return False

    new_content = "\n".join(new_lines)

    with open(filepath, "w") as f:
        f.write(new_content)

    return True


def main():
    skip_dirs = {"scratch", "inbox"}
    modified = 0
    skipped = 0
    total = 0

    for root, dirs, files in os.walk(PROBLEMS_DIR):
        # Skip scratch/ and inbox/ directories
        dirs[:] = [d for d in dirs if d not in skip_dirs]

        for filename in sorted(files):
            if not (filename.endswith(".py") or filename.endswith(".cpp")):
                continue

            filepath = os.path.join(root, filename)
            total += 1

            if process_file(filepath):
                rel = os.path.relpath(filepath, PROBLEMS_DIR)
                print(f"  Updated: {rel}")
                modified += 1
            else:
                skipped += 1

    print(
        f"\nDone. {modified} files updated, {
            skipped} files skipped, {total} total files scanned."
    )


if __name__ == "__main__":
    main()
