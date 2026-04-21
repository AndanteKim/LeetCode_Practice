class UnionFind:
    def __init__(self, n: int):
        self.parent = list(range(n))
        self.rank = [0] * n
    
    def find(self, x: int) -> int:
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x: int, y: int) -> None:
        x, y = self.find(x), self.find(y)

        if x == y:
            return

        if self.rank[x] < self.rank[y]:
            x, y = y, x
        
        self.parent[y] = x

        if self.rank[x] == self.rank[y]:
            self.rank[x] += 1

class Solution:
    def minimumHammingDistance(self, source: List[int], target: List[int], allowedSwaps: List[List[int]]) -> int:
        n = len(source)
        uf = UnionFind(n)

        for a, b in allowedSwaps:
            uf.union(a, b)

        sets = defaultdict(lambda: defaultdict(int))
        for i in range(n):
            f = uf.find(i)
            sets[f][source[i]] += 1
        
        ans = 0
        for i in range(n):
            f = uf.find(i)
            if sets[f][target[i]] > 0:
                sets[f][target[i]] -= 1
            else:
                ans += 1
        
        return ans
