class UnionFind:
    def __init__(self, size: int):
        self.parent, self.rank = list(range(size)), [0] * size
        
    def find(self, x: int) -> int:
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    
    def union(self, x: int, y: int) -> None:
        xset, yset = self.find(x), self.find(y)
        
        if self.rank[xset] < self.rank[yset]:
            self.parent[xset] = yset
        elif self.rank[xset] > self.rank[yset]:
            self.parent[yset] = xset
        else:
            self.parent[yset] = xset
            self.rank[xset] += 1
        

class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        uf = UnionFind(n)
        
        for start, end in edges:
            uf.union(start, end)
        
        return uf.find(source) == uf.find(destination)