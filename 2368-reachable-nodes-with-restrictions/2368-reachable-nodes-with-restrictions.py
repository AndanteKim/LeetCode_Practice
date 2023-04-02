class UnionFind:
    def __init__(self, size: int):
        self.parent, self.rank = [i for i in range(size)], [1] * size
    
    def find(self, x: int) -> int:
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    
    def union_set(self, x: int, y: int) -> None:
        xset, yset = self.find(x), self.find(y)
        
        if xset == yset:
            return
        else:
            if self.rank[xset] > self.rank[yset]:
                xset, yset = yset, xset
            self.rank[yset] += self.rank[xset]
            self.parent[xset] = yset
            
    def getSize(self, node: int) -> int:
        return self.rank[self.find(node)]
            

class Solution:
    def reachableNodes(self, n: int, edges: List[List[int]], restricted: List[int]) -> int:
        uf = UnionFind(n)
        restricted = set(restricted)
        
        for start, end in edges:
            if start not in restricted and end not in restricted:
                uf.union_set(start, end)
        
        
        return uf.getSize(0)