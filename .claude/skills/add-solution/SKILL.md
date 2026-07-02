---
name: add-solution
description: >-
  Add a finished DSA solution to this repo from a problem link plus the solution
  code. Use this whenever the user wants to file, save, commit, or "add" a
  LeetCode / Codeforces / CF-EDU solution they've already written — even if they
  just paste a URL and a code block without saying the word "skill". Handles
  scaffolding via ./scripts/new and fills in the metadata header (complexity,
  notes, tags) in the user's established style.
---

# Add a DSA solution

Turn a problem link + a finished solution into a properly-filed, fully-annotated
solution file in this repo. You do the judgment (platform, pattern, tags,
complexity, notes); `./scripts/new` does the mechanical scaffolding.

## Inputs

The user gives two things, in this order:

1. **Problem link** — a LeetCode, Codeforces, or Codeforces-EDU URL.
2. **Solution code** — the full, finished solution (a `class Solution { ... }` /
   `class Solution:` block, or a competitive-programming `main`).

If either is missing, ask for it before doing anything else. Don't invent a
solution — the user has already written it.

## Why this exists

Filing a solution by hand means: figuring out the platform/id/difficulty,
picking the right `problems/<pattern>/` directory, choosing tags, running
`./scripts/new` with the exact arg order, then hand-writing the metadata header
in a consistent voice. This skill does all of that so the user only has to paste
two things.

`CLAUDE.md` at the repo root is the source of truth for the file format, the
pattern directory table, the tag vocabulary, and the notes/complexity style.
Read it if you're unsure about any convention — the rules below are a summary.

## Workflow

### 1. Identify the platform and gather metadata

From the URL:

| URL shape | platform | id passed to `./scripts/new` |
|-----------|----------|------------------------------|
| `leetcode.com/problems/<slug>/...` | `lc` | numeric frontend id (e.g. `3612`) |
| `codeforces.com/contest/.../problem/X` or `.../problemset/problem/<n>/<X>` | `cf` | contest+letter (e.g. `1791c`) |
| `codeforces.com/edu/course/.../problem/X` | `cf-edu` | **pass the full URL** — the script parses it |

For **LeetCode**, fetch the id, title, and difficulty straight from the public
GraphQL API using the slug in the URL (don't guess them from memory — verify):

```bash
curl -s 'https://leetcode.com/graphql' -H 'Content-Type: application/json' \
  --data '{"query":"query q($slug:String!){question(titleSlug:$slug){questionFrontendId title difficulty}}","variables":{"slug":"PUT-SLUG-HERE"}}'
```

This returns `questionFrontendId`, `title`, and `difficulty` (`Easy`/`Medium`/`Hard`).

For **Codeforces**, derive the id and name from the URL/title (CF has no
difficulty field — omit it).

### 2. Build the slug

Lowercase, hyphen-separated, from the problem title — **except Roman numerals,
which stay uppercase** in both the slug and the filename (e.g.
`...-special-operations-I`, `...-II`, `jump-game-VII`). The `new` script turns
the slug back into the `name:` field by replacing hyphens with spaces, so the
slug fully determines the displayed name.

### 3. Detect the language

Infer from the pasted code: `#include` / `vector` / `class Solution {` → `cpp`;
`def ` / `class Solution:` / `from typing` → `py`. If genuinely ambiguous, ask.

### 4. Choose the pattern and tags

**Pattern** = the `problems/<pattern>/` directory. Pick by the solution's
*overarching conceptual driver*, not the literal control structure used (e.g. a
BFS queue that works because of a monotonic forward window → `sliding_window/`,
not `graphs/bfs/`; record the implementation flavor as a tag instead). See the
pattern table in `CLAUDE.md` for the full list and subcategories.

**Tags** describe techniques, data structures, and problem characteristics.
Lowercase, hyphen-separated, singular (`array` not `arrays`, `two-pointers` not
`two_pointers`), comma-separated with no spaces. See the tag table in `CLAUDE.md`.

### 5. Scaffold with `./scripts/new`

```bash
./scripts/new <platform> <id> <slug> <lang> <pattern> <tags>
```

For `cf-edu`, pass the full problem URL in place of `<id>`. The script creates
the file under `problems/<pattern>/`, fills `platform`/`id`/`name`/`pattern`/`tags`
(and `url`/`course`/`lesson` for cf-edu), appends a row to the right
`tracks/.../README.md`, and refreshes the README stats. Don't do any of that by
hand — let the script do it, then read the file it reports back.

If the script errors because the file already exists, surface that to the user
rather than overwriting.

### 6. Fill in the header and paste the solution

Open the scaffolded file and finish the metadata block, then drop the solution
into the class body (replace the `# paste method here` / placeholder).

For **LeetCode**, add `difficulty:` and `url:` lines under `name:` (the bare
templates omit them, but the documented format includes them):

```
platform: lc
id: 3612
name: process string with special operations I
difficulty: medium
url: https://leetcode.com/problems/process-string-with-special-operations-i/
pattern: strings
tags: simulation,string,bytearray
complexity:
...
```

**Complexity** — declare any helper variables on their own line(s) *first*, then
the `time`/`space` lines. Add qualifiers inline where they matter:

```
complexity:
L = final length of res
- time = O(n + L), reverses can push worst case to O(n * L)
- space = O(L)
```

(e.g. `- space = O(26) = O(1) for fixed alphabet size`)

Use the **standard mathematical names** for a problem's size parameters so the
complexity reads the way the literature does — declare the helper variable once,
then use it in the `time`/`space` lines. Common conventions:

| Domain | Variables |
|--------|-----------|
| Graphs | `V` = vertices/nodes, `E` = edges (capitalized). Grid graphs: `V = m*n` cells, `E = O(4*V)` |
| Trees | `n` = nodes, `h` = height, `d` = depth |
| Strings | `n`, `m` = lengths of the two strings; `k` = alphabet / distinct chars |
| Matrix / grid | `m` = rows, `n` = cols (raw dims, when not framed as a graph) |
| Numeric / value-range | `k` or `W` = max value / weight; `B` = number of bits |
| Heap / sort | `n` = elements, `k` = heap size or number of lists |

For **graph solutions**, prefer the canonical `V`/`E` form and pin it to the
concrete grid/adjacency size on the same line, so both the algorithmic and the
input-shaped complexity are visible:

```
complexity:
V = m*n grid cells (vertices), E = O(4*V) grid edges
- time = O(E log V) = O(m*n log(m*n))    # dijkstra with a binary heap
- space = O(V) = O(m*n)
```

Match the algorithm's textbook bound: BFS/DFS `O(V + E)`, Dijkstra (binary heap)
`O(E log V)`, Bellman-Ford `O(V*E)`, Floyd-Warshall `O(V^3)`, union-find
`O(E α(V))`, topological sort `O(V + E)`.

**Notes** — concise and casual: short lowercase lines, not formal prose. Captur
the core idea plus any tie-break / edge detail; skip step-by-step narration.
Length scales with difficulty:
- easy: ~2 short lines (sometimes a one-liner like `just simulate it bro` is in keeping)
- medium: a couple of short lines
- hard: a bit more depth, but still trim the fluff

Preserve the user's own inline comments in the pasted code verbatim — they're
part of how they document solutions.

### 7. Report — don't commit

Tell the user the path of the created file and a one-line summary of the
pattern/tags/complexity you chose, so they can sanity-check the judgment calls.
**Do not `git commit`** unless the user explicitly asks. If they do, the message
format is `solved LC/CF/CF-EDU #ID - description`, and per the user's global
rule commits are solo-authored — never add a Claude co-author trailer.

## Example

Input: link `https://leetcode.com/problems/process-string-with-special-operations-i/`
plus a Python `processStr` solution that builds a `bytearray`.

Actions: GraphQL → id `3612`, "Process String with Special Operations I", Medium
→ slug `process-string-with-special-operations-I` → lang `py` → pattern `strings`
(it's a straight op-by-op simulation) → tags `simulation,string,bytearray` →
`./scripts/new lc 3612 process-string-with-special-operations-I py strings simulation,string,bytearray`
→ fill `difficulty: medium`, the `url:`, complexity with an `L = final length`
helper line, casual notes → paste the code → report the path.
