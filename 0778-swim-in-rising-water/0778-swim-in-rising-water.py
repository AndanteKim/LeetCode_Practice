class UnionFind:
    def __init__(self, n: int):
        self.parents = list(range(n ** 2))
        self.size = [1] * (n ** 2)
    
    def find(self, x: int) -> int:
        if x != self.parents[x]:
            self.parents[x] = self.find(self.parents[x])
        return self.parents[x]
    
    def union(self, x: int, y: int) -> None:
        xset, yset = self.find(x), self.find(y)
        
        if xset == yset:
            return
        if self.size[xset] > self.size[yset]:
            self.parents[yset] = xset
        elif self.size[xset] == self.size[yset]:
            self.parents[yset] = xset
            self.size[xset] += 1
        else:
            self.parents[xset] = yset
        

class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        n = len(grid)
        visited = [[False] * n for _ in range(n)]
        positions = sorted([(i, j) for i in range(n) for j in range(n)], key = lambda x: grid[x[0]][x[1]])
        
        uf = UnionFind(n);
        for i, j in positions:
            for x, y in (i + 1, j), (i - 1, j), (i, j - 1), (i, j + 1):
                if 0 <= x < n and 0 <= y < n and visited[x][y]:
                    uf.union(i * n + j, x * n + y)
            
            if uf.find(0) == uf.find(n * n - 1):
                return grid[i][j]
            visited[i][j] = True
        return -1