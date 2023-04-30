class UnionFind:
    def __init__(self, size: int):
        self.parent, self.rank, self.components = [i for i in range(size + 1)], [1] * (size + 1), size
    
    def find(self, x: int) -> int:
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    
    def union_set(self, x: int, y: int) -> int:
        xset, yset = self.find(x), self.find(y)
        
        if xset == yset:
            return 0
        
        if self.rank[xset] < self.rank[yset]:
            self.rank[yset] += self.rank[xset]
            self.parent[xset] = yset
        else:
            self.rank[xset] += self.rank[yset]
            self.parent[yset] = xset
        self.components -= 1
        return 1
    
    def is_connected(self) -> bool:
        return self.components == 1

class Solution:
    def maxNumEdgesToRemove(self, n: int, edges: List[List[int]]) -> int:
        Alice, Bob = UnionFind(n), UnionFind(n)
        
        edgesRequired = 0
        
        for edge in edges:
            if edge[0] == 3:
                edgesRequired += (Alice.union_set(edge[1], edge[2]) |\
                                  Bob.union_set(edge[1], edge[2]))
        
        for edge in edges:
            if edge[0] == 1:
                edgesRequired += Alice.union_set(edge[1], edge[2])
            elif edge[0] == 2:
                edgesRequired += Bob.union_set(edge[1], edge[2])
        
        if Alice.is_connected() & Bob.is_connected():
            return len(edges) - edgesRequired
        
        return -1