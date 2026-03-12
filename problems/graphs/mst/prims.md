# prim's
single-source greedy algorithm that **grows** MST by repeatedly adding the lightest edge that connects the current tree to a new vertex.
**dijkstra's, but for MST** -> grows MST by greedily adding smallest edge of an unvisited node to the MST at each step (via priority queue)

## in a nutshell
start from any vertex, push all outgoing edges into a min-heap, and keep choosing the smallest edge that reaches an unvisited vertex. continue until all vertices are in the tree. works on **undirected** graphs with non-negative weights. uses DSU/Union-Find structure to manage MST.

## steps
1. build an **undirected** adjacency list and pick an arbitrary start vertex.
2. push (0, start) into a min-heap keyed by edge weight; mark no vertices as visited yet.
3. pop the smallest (w, u); if u is already in the tree, skip; otherwise add u and **accumulate w**.
4. push all edges (w(u, v), v) where v is not yet in the tree.
5. repeat until all vertices are added; if some remain unreachable, the graph is disconnected (no mst).

## complexity analysis
- with a binary heap and adjacency list: **time**: O(E log V), **space**: O(E).

## caveats
- requires graph to be undirected
- works best on dense graphs (E ≅ V*V = V^2, i.e. many edges)

