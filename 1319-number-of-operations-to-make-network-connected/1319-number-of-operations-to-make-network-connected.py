class UnionFind:
    def __init__(self, size: int):
        self.parent, self.rank = [], [0] * size
        for i in range(size):
            self.parent.append(i)
            
    def find(self, x: int) -> int:
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    
    def union_set(self, x: int, y: int) -> None:
        xset, yset = self.find(x), self.find(y)
        if self.rank[xset] < self.rank[yset]:
            self.parent[xset] = yset
        elif self.rank[xset] > self.rank[yset]:
            self.parent[yset] = xset
        else:
            self.parent[yset] = xset
            self.rank[xset] += 1
        

class Solution:
    def makeConnected(self, n: int, connections: List[List[int]]) -> int:
        if len(connections) < n - 1:
            return -1
        
        dsu, connected = UnionFind(n), n
        
        for connection in connections:
            if dsu.find(connection[0]) != dsu.find(connection[1]):
                connected -= 1
                dsu.union_set(connection[0], connection[1])
        
        return connected - 1
        
        