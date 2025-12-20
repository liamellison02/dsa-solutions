# dijkstra's algorithm

single-source shortest distance graph traversal algorithm

## in a nutshell

a greedy path traversal algorithm where you take the shortest step possible at all times.

0. create adj list/matrix + hash table to record shortest distance to all nodes.

1. begin algorithm by pushing the following pair of values to a min heap:
  - the source node
  - the distance to the source node (which is 0)

2. pop from the top, and if the distance to the popped node is < shortest distance recorded in the hash table, update the table with the new shortest distance.

3. push any reachable nodes from the popped node that are a shorter **TOTAL** distance than what is currently recorded in the hash table.

4. repeat until min heap is empty, returning the shortest recorded distance in the hash table for the target node.

## complexity analysis

V = order of graph/# of vertices
E = size of graph/# of edges

the worst case scenario for dijkstra's (for both time & space) is if we have a complete graph.
reasoning:
- dijkstra's deals with traversing over all EDGES, and in a complete graph, all vertices are adjacent, meaning we will have to traverse through V-1 edges for all V vertices (V \* V-1 = O(V^2)).
- each edge traversal also incurs a push/pop operation to the heap, adding a logarithmic operation for all (worst case V\*V-1) edges.
- so the time complexity is O(E \* logE), where in the worst case, E = V\*V-1 for complete graphs.
- in this case (and if we also consider multigraphs), our heap can at worst grow to a size of essentially O(V^2).

- time: O(E\*logE)
- space: O(E)

where in the worst-case, E = V \* V-1.


