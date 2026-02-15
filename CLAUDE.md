# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

This is a personal Data Structures and Algorithms (DSA) solutions repository containing Python and C++ solutions to problems from LeetCode, Codeforces, Grind 75, and university coursework.

## Common Commands

```bash
# Create a new problem file with template and metadata
./scripts/new <platform> <id> <slug> <lang> <pattern> [tags]

# Examples:
./scripts/new lc 125 valid-palindrome cpp arrays/two_pointers palindrome,string
./scripts/new lc 3 longest-substring-without-repeating py sliding_window hashset
./scripts/new cf 4A watermelon cpp math divisibility

# Show stats breakdown by platform, difficulty, pattern, language, and tags
./scripts/stats
```

There is no build system, test framework, or linting configured—solutions are standalone files.

## Code Organization

**`problems/`** - Solutions organized by algorithm pattern:

| Pattern | Subcategories |
|---------|---------------|
| `arrays/` | `hashing/`, `intervals/`, `prefix_sum/`, `simulation/`, `sorting/`, `two_pointers/` |
| `backtracking/` | |
| `binary_search/` | `on_answer/`, `on_array/` |
| `design/` | |
| `dp/` | `linear/`, `two_string/`, `lis/`, `grid/`, `interval/`, `state_machine/`, `bitmask/` |
| `graphs/` | `bfs/`, `dsu/`, `mst/`, `shortest_path/`, `topo/`, `traversal/` |
| `greedy/` | |
| `heap/` | |
| `linked_list/` | `fast_slow/` |
| `math/` | `geometry/`, `number_theory/` |
| `sliding_window/` | |
| `stack/` | `monotonic/` |
| `strings/` | |
| `trees/` | `bfs/`, `bst/`, `construct/`, `dfs/`, `lca/`, `traversal/` |
| `inbox/` | Legacy/uncategorized problems |
| `scratch/` | Work in progress |

**`tracks/`** - Problem tracking by platform/course (leetcode, codeforces, grind75, janestreet, csc_2720, codepath_tip102)

**`templates/`** - Language and platform-specific templates (`lc.py`, `lc.cpp`, `cf.py`, `cf.cpp`)

## Solution File Format

All solutions must include this metadata header:

```python
"""
platform: lc              # lc or cf
id: 1
name: two-sum
difficulty: easy          # easy, medium, hard (LC only)
url: https://leetcode.com/problems/two-sum/
pattern: arrays/hashing
tags: hashmap,complement
complexity:
- time = O(n)
- space = O(n)
notes: use hashmap to store complement; for each num check if target - num already seen
"""
```

## Tags

Tags describe the **techniques, data structures, and problem characteristics** used in a solution. They are comma-separated in the `tags:` metadata field.

**Formatting rules:**
- Lowercase, hyphen-separated (e.g. `two-pointers`, not `two_pointers` or `twoPointers`)
- No spaces around commas: `tags: greedy,sorting,hashing`
- Use singular form: `array` not `arrays`, `string` not `strings`

**Common tags by category:**

| Category | Tags |
|----------|------|
| Data structures | `array`, `linked-list`, `tree`, `binary-tree`, `bst`, `stack`, `queue`, `heap`, `matrix`, `grid`, `hashing`, `hashmap`, `hashset` |
| Traversal / search | `bfs`, `dfs`, `binary-search`, `two-pointers`, `sliding-window`, `recursion`, `iterative` |
| Sorting / ordering | `sorting`, `greedy`, `intervals`, `merge` |
| DP techniques | `dp`, `bottom-up`, `1d-dp`, `2d-dp`, `grid-dp`, `interval-dp`, `kadanes`, `subsequence`, `bitmask` |
| Graph algorithms | `dijkstras`, `topological`, `kahns`, `union-find`, `shortest-path`, `mst`, `dag`, `cycle` |
| Tree techniques | `lca`, `inorder-traversal`, `postorder` |
| String techniques | `string`, `palindrome`, `substring`, `subsequence`, `regex`, `decoding`, `encoding`, `case-conversion` |
| Math | `math`, `geometry`, `number-theory`, `combinatorics`, `divisibility`, `primes`, `factorization` |
| Stack / queue variants | `monotonic-stack`, `monotonic-queue`, `minheap`, `priority-queue` |
| Problem characteristics | `simulation`, `design`, `backtracking`, `precompute`, `prefix-sum`, `counting`, `frequency`, `complement`, `enumeration`, `overlap`, `circular-array`, `bruteforce` |
| Bit manipulation | `bit`, `bitmask`, `bit-manipulation` |

## Conventions

- Use the `./scripts/new` script to create new problem files (handles templates and metadata automatically)
- Place solutions in the appropriate `problems/<pattern>/` directory
- Commit messages follow: "solved LC/CF #ID - description"
- Templates include common STL imports for C++ and typing imports for Python
- Scripts are cross-platform (macOS BSD and Linux GNU compatible)
