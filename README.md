# dsa-solutions

personal data structures & algorithms repository for solutions, write-ups, and any other algorithmic "explorations".
includes c++ & python solutions to problems from LeetCode, Codeforces, ICPC prep, university coursework, and more.

## stats

<!-- stats-start -->
| | Count |
|---|---|
| Total solutions | 270 |
| LeetCode | 164 |
| Codeforces | 20 |
| CF EDU | 1 |
| CodePath | 79 |
| CSC 2720 | 1 |
| Jane Street | 1 |
| Python | 139 |
| C++ | 131 |
<!-- stats-end -->

run `./scripts/stats` for a full breakdown by difficulty, pattern, and tags.

## pattern directories

solutions are organized by algorithm/solution pattern in `problems/`:

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

## usage

### create a new solution

```bash
./scripts/new <platform> <id> <slug> <lang> <pattern> [tags]

# examples:
./scripts/new lc 125 valid-palindrome cpp arrays/two_pointers palindrome,string
./scripts/new lc 3 longest-substring-without-repeating py sliding_window hashset
./scripts/new cf 4A watermelon cpp math divisibility
```

### solution metadata format

every solution includes a metadata header:

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

## tracks

solutions can also be browsed by platform/course in `tracks/`:

- [LeetCode](tracks/leetcode/)
- [Codeforces](tracks/codeforces/)
- [Codeforces EDU](tracks/cf_edu/)
- [Jane Street](tracks/janestreet/)
- [CodePath TIP102](tracks/codepath_tip102/)
- [CSC 2720](tracks/csc_2720/)
