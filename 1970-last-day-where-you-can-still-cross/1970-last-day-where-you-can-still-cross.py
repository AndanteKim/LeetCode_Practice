class DSU:
    def __init__(self, n: int):
        self.parents = list(range(n))
        self.rank = [1] * n
        
    def find(self, x: int) -> int:
        if self.parents[x] != x:
            self.parents[x] = self.find(self.parents[x])
        return self.parents[x]
    
    def union(self, x: int, y: int) -> None:
        xset, yset = self.find(x), self.find(y)
        
        if xset == yset:
            return
        if self.rank[xset] > self.rank[yset]:
            xset, yset = yset, xset
        self.parents[xset] = yset
        self.rank[yset] = self.rank[xset]

class Solution:
    def latestDayToCross(self, row: int, col: int, cells: List[List[int]]) -> int:
        dsu = DSU(row * col + 2)
        grid = [[1] * col for _ in range(row)]
        directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        
        for i in range(len(cells) - 1, -1, -1):
            r, c = cells[i][0] - 1, cells[i][1] - 1
            grid[r][c] = 0
            idx1 = r * col + c + 1
            for dr, dc in directions:
                new_r, new_c = r + dr, c + dc
                idx2 = new_r * col + new_c + 1
                if 0 <= new_r < row and 0 <= new_c < col and grid[new_r][new_c] == 0:
                    dsu.union(idx1, idx2)
            
            if r == 0:
                dsu.union(0, idx1)
            if r == row - 1:
                dsu.union(row * col + 1, idx1)
            if dsu.find(0) == dsu.find(row * col + 1):
                return i
        return -1