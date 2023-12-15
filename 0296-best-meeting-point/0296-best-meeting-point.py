class Solution:
    def _min_distance_1d(self, points: List[int], origin: int) -> int:
        dist = 0
        i, j = 0, len(points) - 1
        while i < j:
            dist += points[j] - points[i]
            i += 1
            j -= 1
        
        return dist
    
    def _collect_rows(self, grid: List[List[int]]) -> List[int]:
        rows = []
        for row in range(0, len(grid)):
            for col in range(0, len(grid[0])):
                if grid[row][col]:
                    rows.append(row)
        return rows
    
    def _collect_cols(self, grid: List[List[int]]) -> List[int]:
        cols = []
        for col in range(0, len(grid[0])):
            for row in range(0, len(grid)):
                if grid[row][col]:
                    cols.append(col)
        return cols
    
    def minTotalDistance(self, grid: List[List[int]]) -> int:
        rows, cols = self._collect_rows(grid), self._collect_cols(grid)
        row, col = rows[len(rows) // 2], cols[len(cols) // 2]
        
        return self._min_distance_1d(rows, row) + self._min_distance_1d(cols, col)