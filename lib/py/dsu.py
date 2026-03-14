class DSU:
    """
    DSU: auto-initializes nodes on first access.
    Use when node values are arbitrary or not known ahead of time.
    """

    def __init__(self):
        self.root = {}
        self.rank = {}

    def find(self, x: int) -> int:
        if x not in self.root:
            self.root[x] = x
            self.rank[x] = 0
        if self.root[x] == x:
            return x
        self.root[x] = self.find(self.root[x])
        return self.root[x]

    def unite(self, a: int, b: int) -> bool:
        a, b = self.find(a), self.find(b)
        if a == b:
            return False
        if self.rank[a] < self.rank[b]:
            a, b = b, a
        self.root[b] = a
        if self.rank[a] == self.rank[b]:
            self.rank[a] += 1
        return True

    def same(self, a: int, b: int) -> bool:
        return self.find(a) == self.find(b)


class DenseDSU:
    """
    Dense DSU: for nodes 0..n-1. Faster than sparse version.
    Use for graphs, grid problems, etc.
    """

    def __init__(self, n: int):
        self.root = list(range(n))
        self.rank = [0] * n
        self._components = n

    def find(self, x: int) -> int:
        if self.root[x] == x:
            return x
        self.root[x] = self.find(self.root[x])
        return self.root[x]

    def unite(self, a: int, b: int) -> bool:
        a, b = self.find(a), self.find(b)
        if a == b:
            return False
        if self.rank[a] < self.rank[b]:
            a, b = b, a
        self.root[b] = a
        if self.rank[a] == self.rank[b]:
            self.rank[a] += 1
        self._components -= 1
        return True

    def same(self, a: int, b: int) -> bool:
        return self.find(a) == self.find(b)

    @property
    def components(self) -> int:
        return self._components
