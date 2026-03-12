# minimum spanning tree / mst
connect all vertices of a connected, weighted **undirected** graph with the minimum total edge weight and **no cycles**.

## in a nutshell
an mst is a spanning tree with the smallest possible weight. it has exactly **n-1 edges** for **n** vertices and may not be unique (ties can exist). two classic ways to build it are **prim's** (grow from a seed) and **kruskal's** (add edges light-to-heavy while avoiding cycles).

## properties & steps (concept)
1. consider only **undirected** edges with non-negative weights (standard mst setting).
2. the mst must connect all vertices (one component) and be acyclic.
3. cut and cycle properties: the lightest edge crossing any cut is **safe**; the heaviest edge on any cycle is **unsafe**.
4. construct via prim's or kruskal's and return the sum of picked edge weights.

## complexity (via standard algorithms)
- prim's with a binary heap: **time**: O(E log V), **space**: O(E).
- kruskal's with union-find: **time**: O(E log E) (for sorting), **space**: O(V).
