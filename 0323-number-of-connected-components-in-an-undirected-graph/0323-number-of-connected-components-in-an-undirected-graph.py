class UnionFind:
    def __init__(self, size: int):
        self.parents, self.rank = [i for i in range(size)], [0] * size
        
    def find(self, x: int) -> int:
        if self.parents[x] != x:
            self.parents[x] = self.find(self.parents[x])
        return self.parents[x]

    def union_set(self, x: int, y: int) -> int:
        xset, yset = self.find(x), self.find(y)
        if xset == yset:
            return 0
        else:
            if self.rank[xset] > self.rank[yset]:
                self.rank[xset] += self.rank[yset]
                self.parents[yset] = xset
            else:
                self.rank[yset] += self.rank[xset]
                self.parents[xset] = yset
            return 1

class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        components = n
        uf = UnionFind(n)
        for edge in edges:
            components -= uf.union_set(edge[0], edge[1])
        return components