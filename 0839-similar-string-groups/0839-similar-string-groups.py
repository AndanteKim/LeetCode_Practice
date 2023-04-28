class UnionFind:
    def __init__(self, size: int):
        self.parent, self.rank = [i for i in range(size)], [0] * size
        
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
    def isSimilar(self, a: str, b: str) -> bool:
        diff = 0
        for i in range(len(a)):
            if a[i] != b[i]:
                diff += 1
        return diff == 0 or diff == 2
    
    def numSimilarGroups(self, strs: List[str]) -> int:
        n = len(strs)
        dsu = UnionFind(n)
        ans = n
        
        for i in range(n):
            for j in range(i + 1, n):
                if self.isSimilar(strs[i], strs[j]) and dsu.find(i) != dsu.find(j):
                    ans -= 1
                    dsu.union_set(i, j)
        
        return ans