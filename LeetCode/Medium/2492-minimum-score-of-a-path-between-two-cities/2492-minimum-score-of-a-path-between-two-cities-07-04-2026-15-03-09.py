class UnionFind:
    def __init__(self, size: int):
        self.parent = list(range(size))
        self.rank = [0] * size

    def find(self, x: int) -> int:
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    
    def union_set(self, x: int, y: int) -> None:
        x_set, y_set = self.find(x), self.find(y)

        if x_set == y_set:
            return
        elif self.rank[x_set] < self.rank[y_set]:
            self.parent[x_set] = y_set
        elif self.rank[x_set] > self.rank[y_set]:
            self.parent[y_set] = x_set
        else:
            self.parent[y_set] = x_set
            self.rank[x_set] += 1


class Solution:
    def minScore(self, n: int, roads: List[List[int]]) -> int:
        dsu = UnionFind(n + 1)
        ans = float('inf')

        for u, v, _ in roads:
            dsu.union_set(u, v)

        for u, _, cost in roads:
            if dsu.find(1) == dsu.find(u):
                ans = min(ans, cost)
        
        return ans