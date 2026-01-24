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
```

There is no build system, test framework, or linting configured—solutions are standalone files.

## Code Organization

**`problems/`** - Solutions organized by algorithm pattern:

| Pattern | Subcategories |
|---------|---------------|
| `arrays/` | `difference/`, `hashing/`, `intervals/`, `matrix/`, `prefix_sum/`, `simulation/`, `sorting/`, `two_pointers/` |
| `backtracking/` | |
| `binary_search/` | `on_answer/`, `on_array/` |
| `bit/` | `bitmask/`, `xor/` |
| `design/` | |
| `dp/` | `1D/`, `2D/`, `bitmask/`, `digit/`, `grid/`, `interval/`, `knapsack/`, `lcs/`, `lis/`, `states/`, `trees/` |
| `graphs/` | `bfs/`, `dsu/`, `shortest_path/`, `topo/`, `traversal/` |
| `greedy/` | |
| `heap/` | |
| `linked_list/` | `fast_slow/`, `reversal/` |
| `math/` | `combinatorics/`, `geometry/`, `number_theory/` |
| `queue/` | `monotonic/` |
| `set/` | |
| `sliding_window/` | |
| `stack/` | `monotonic/` |
| `strings/` | `kmp_z/`, `rolling_hash/`, `trie/` |
| `trees/` | `bfs/`, `dfs/`, `lca/` |
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
pattern: arrays/hashing
tags: hashmap,complement
complexity:
- time = O(n)
- space = O(n)
notes:
"""
```

## Conventions

- Use the `./scripts/new` script to create new problem files (handles templates and metadata automatically)
- Place solutions in the appropriate `problems/<pattern>/` directory
- Commit messages follow: "solved LC/CF #ID - description"
- Templates include common STL imports for C++ and typing imports for Python
- Scripts are cross-platform (macOS BSD and Linux GNU compatible)
