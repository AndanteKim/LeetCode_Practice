class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        n = len(grid)
        seen = {(0, 0)}
        pq, ans = [(grid[0][0], 0, 0)], 0
        
        while pq:
            dist, row, col = heappop(pq)
            ans = max(ans, dist)
            if row == col == n - 1:
                return ans
            for cr, cc in ((row - 1, col), (row + 1, col), (row, col - 1), (row, col + 1)):
                if 0 <= cr < n and 0 <= cc < n and (cr, cc) not in seen:
                    heappush(pq, (grid[cr][cc], cr, cc))
                    seen.add((cr, cc))
        return -1