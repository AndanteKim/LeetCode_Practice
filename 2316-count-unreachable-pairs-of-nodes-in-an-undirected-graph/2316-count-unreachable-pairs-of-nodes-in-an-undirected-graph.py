class UnionFind:
    def __init__(self, size):
        self.parent, self.rank = [], [0] * size
        for i in range(size):
            self.parent.append(i)
            
    def find(self, x: int) -> int:
        if self.parent[x] != x:
            return self.find(self.parent[x])
        return x
    
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
    def countPairs(self, n: int, edges: List[List[int]]) -> int:
        dsu = UnionFind(n)
        numberOfPairs, remainingNodes = 0, n
        sizeOfComponent = defaultdict(int)
        
        for start, end in edges:
            dsu.union_set(start, end)
            
        for node in range(n):
            sizeOfComponent[dsu.find(node)] += 1
            
        for node in range(n):
            componentSize = sizeOfComponent[node]
            numberOfPairs += componentSize * (remainingNodes - componentSize)
            remainingNodes -= componentSize
        return numberOfPairs