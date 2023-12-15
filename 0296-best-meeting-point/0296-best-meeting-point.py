class Solution:
    def minTotalDistance(self, grid: List[List[int]]) -> int:
        def min_distance_1d(points: List[int], origin: int) -> int:
            dist = 0
            for point in points:
                dist += abs(point - origin)
            return dist
        
        rows, cols, m, n = [], [], len(grid), len(grid[0])
        for r in range(m):
            for c in range(n):
                if grid[r][c]:
                    rows.append(r)
                    cols.append(c)
        
        cols.sort()
        row, col = rows[len(rows) // 2], cols[len(cols) // 2]
        return min_distance_1d(rows, row) + min_distance_1d(cols, col)