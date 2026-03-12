# kruskal's
edge-based greedy algorithm that builds MST by adding edges in **increasing** weight order while **avoiding cycles**.

## in a nutshell
sort all edges by weight and scan from lightest to heaviest. use **union-find** to test whether adding an edge connects two different components; if yes, take it, otherwise skip.

## steps
1. collect all vertices and sort edges ascending by weight.
2. initialize dsu so each vertex is its own set.
3. for each edge (u, v, w) in order: if find(u) != find(v), take the edge (union(u, v)) and add **w** to the total.
4. stop after taking **V-1** edges; if fewer were taken and edges are exhausted, the graph is disconnected (no mst).

## complexity analysis
- dominated by sorting: **time**: O(E log E) (≈ O(E log V)).
- union-find ops are almost constant: **O(α(V))** each; **space**: O(V).

## caveats
- works best on sparse graphs (E ≅ V or less edges), where sorting the edges by weight is cheaper than using a heap

