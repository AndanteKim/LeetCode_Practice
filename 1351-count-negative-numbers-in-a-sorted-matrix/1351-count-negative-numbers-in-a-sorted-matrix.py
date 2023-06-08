class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        r, c, i = len(grid) - 1, len(grid[0]), 0
        ans = 0
        
        while i < c and r >= 0:
            if grid[r][i] >= 0:
                i += 1
            else:
                ans += c - i
                r -= 1
        
        return ans