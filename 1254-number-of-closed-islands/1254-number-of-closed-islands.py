class UnionFind:
    def __init__(self, size: int):
        self.parents, self.ranks = list(range(size)), [0] * size
        
    def find(self, x : int) -> int:
        if self.parents[x] != x:
            self.parents[x] = self.find(self.parents[x])
        return self.parents[x]
    
    def union_set(self, x: int, y: int) -> None:
        xset, yset = self.find(x), self.find(y)
        if xset == yset:
            return
        
        if self.ranks[xset] < self.ranks[yset]:
            self.parents[xset] = yset
        elif self.ranks[xset] > self.ranks[yset]:
            self.parents[yset] = xset
        else:
            self.parents[yset] = xset
            self.ranks[xset] += 1

class Solution:
    def closedIsland(self, grid: List[List[int]]) -> int:
        m, n, islands = len(grid), len(grid[0]), 0
        
        uf = UnionFind(m * n)
        for y in range(m):
            for x in range(n):
                if grid[y][x] == 0:
                    islands += 1
                    for dy, dx in ((1, 0), (0, 1), (-1, 0), (0, -1)):
                        new_row, new_col = y + dy, x + dx
                        if 0 <= new_row < m and 0 <= new_col < n and grid[new_row][new_col] == 0:
                            if uf.find(y * n + x) != uf.find(new_row * n + new_col):
                                islands -= 1
                                uf.union_set(y * n + x, new_row * n + new_col)
        
        open_islands = set()
        for y in range(m):
            if grid[y][0] == 0:
                open_islands.add(uf.find(y * n))
            if grid[y][n-1] == 0:
                open_islands.add(uf.find(y * n + (n - 1)))
        
        for x in range(n):
            if grid[0][x] == 0:
                open_islands.add(uf.find(x))
            if grid[m - 1][x] == 0:
                open_islands.add(uf.find((m - 1) * n + x))
        return islands - len(open_islands)