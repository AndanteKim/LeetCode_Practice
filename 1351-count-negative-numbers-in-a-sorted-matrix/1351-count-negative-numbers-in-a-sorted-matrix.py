class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        
        m, n, ans = len(grid), len(grid[0]), 0
        for i in range(m):
            left, right = 0, n
            while left < right:
                mid = (left + right) // 2
                if grid[i][mid] >= 0:
                    left = mid + 1
                else:
                    right = mid
            ans += n - left
            
        return ans