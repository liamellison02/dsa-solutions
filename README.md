# DSA Solutions

Personal Data Structures and Algorithms solutions repository. Python and C++ solutions to problems from LeetCode, Codeforces, Grind 75, and university coursework.

## Stats

<!-- stats-start -->
| | Count |
|---|---|
| Total solutions | 200 |
| LeetCode | 102 |
| Codeforces | 15 |
| CF EDU | 1 |
| CodePath | 79 |
| CSC 2720 | 1 |
| Jane Street | 1 |
| Python | 107 |
| C++ | 93 |
<!-- stats-end -->

Run `./scripts/stats` for a full breakdown by difficulty, pattern, and tags.

## Pattern Directory

Solutions are organized by algorithm pattern in `problems/`:

```
problems/
├── arrays/
│   ├── hashing/          # hashmaps, hashsets, frequency counting
│   ├── intervals/        # merge, insert, overlap detection
│   ├── prefix_sum/       # prefix sums, 2D prefix sums
│   ├── simulation/       # step-by-step simulation
│   ├── sorting/          # sort-based solutions
│   └── two_pointers/     # left/right pointers, fast/slow
├── bit/                  # bit manipulation, bitwise operations
├── backtracking/         # subset/permutation generation, constraint satisfaction
├── binary_search/
│   ├── on_answer/        # binary search on the answer space
│   └── on_array/         # binary search on sorted data
├── design/               # system/class design problems
├── dp/
│   ├── bitmask/          # bitmask DP, subset enumeration
│   ├── grid/             # 2D grid traversal DP
│   ├── interval/         # interval DP (burst balloons, etc.)
│   ├── linear/           # 1D DP, rolling state
│   ├── lis/              # longest increasing subsequence variants
│   ├── state_machine/    # multi-state transitions (buy/sell stock, etc.)
│   └── two_string/       # 2-sequence DP (edit distance, LCS, interleaving)
├── graphs/
│   ├── bfs/              # breadth-first search, multi-source BFS
│   ├── dsu/              # disjoint set union (union-find)
│   ├── mst/              # minimum spanning tree (Prim's, Kruskal's)
│   ├── shortest_path/    # Dijkstra's, Bellman-Ford
│   ├── topo/             # topological sort, Kahn's algorithm
│   └── traversal/        # DFS/BFS traversal, Eulerian paths
├── greedy/               # greedy choice property
├── heap/                 # heap/priority queue solutions
├── linked_list/
│   └── fast_slow/        # Floyd's cycle detection, middle finding
├── math/
│   ├── geometry/         # coordinate geometry, area calculations
│   └── number_theory/    # primes, divisibility, factorization
├── sliding_window/       # fixed and variable size windows
├── stack/
│   └── monotonic/        # monotonic stack (next greater, histogram)
├── strings/              # string manipulation, pattern matching
└── trees/
    ├── bfs/              # level-order traversal
    ├── bst/              # BST operations, balancing
    ├── construct/        # tree construction
    ├── dfs/              # pre/in/post-order traversal
    ├── lca/              # lowest common ancestor
    └── traversal/        # iterative traversal
```

## Usage

### Create a new solution

```bash
./scripts/new <platform> <id> <slug> <lang> <pattern> [tags]

# Examples:
./scripts/new lc 125 valid-palindrome cpp arrays/two_pointers palindrome,string
./scripts/new lc 3 longest-substring-without-repeating py sliding_window hashset
./scripts/new cf 4A watermelon cpp math divisibility
```

### Solution metadata format

Every solution includes a metadata header:

```python
"""
platform: lc
id: 1
name: two-sum
difficulty: easy
url: https://leetcode.com/problems/two-sum/
pattern: arrays/hashing
tags: hashmap,complement
complexity:
- time = O(n)
- space = O(n)
notes: use hashmap to store complement; for each num check if target - num already seen
"""
```

## Tracks

Solutions can also be browsed by platform/course in `tracks/`:

- [LeetCode](tracks/leetcode/)
- [Codeforces](tracks/codeforces/)
- [Grind 75](tracks/grind75/)
- [CodePath TIP102](tracks/codepath_tip102/)
- [CSC 2720](tracks/csc_2720/)
- [Jane Street](tracks/janestreet/)
