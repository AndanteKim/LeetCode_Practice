class UnionFind:
    def __init__(self, grid: List[List[chr]]):
        self.count, self.parent, self.rank = 0, [], []
        m, n = len(grid), len(grid[0])
        for i in range(m):
            for j in range(n):
                if grid[i][j] == '1':
                    self.parent.append(i * n + j)
                    self.count += 1
                else:
                    self.parent.append(-1)
                self.rank.append(0)
        
    def find(self, x: int) -> int:
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    
    def union_set(self, x: int, y: int) -> None:
        xset, yset = self.find(x), self.find(y)
        
        if xset != yset:
            self.count -= 1
            if self.rank[xset] < self.rank[yset]:
                self.parent[xset] = yset
            elif self.rank[xset] > self.rank[yset]:
                self.parent[yset] = xset
            else:
                self.parent[yset] = xset
                self.rank[xset] += 1

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        nr, nc = len(grid), len(grid[0])
        
        unf, num = UnionFind(grid), 0
        
        for r in range(nr):
            for c in range(nc):
                if grid[r][c] == '1':
                    grid[r][c] == '0'
                    if r >= 1 and grid[r-1][c] == '1':
                        unf.union_set(r * nc + c, (r-1) * nc + c)
                    if r < nr - 1 and grid[r+1][c] == '1':
                        unf.union_set(r * nc + c, (r+1) * nc + c)
                    if c >= 1 and grid[r][c-1] == '1':
                        unf.union_set(r * nc + c, r * nc + c - 1)
                    if c < nc - 1 and grid[r][c+1] == '1':
                        unf.union_set(r * nc + c, r * nc + c + 1)
        
        return unf.count