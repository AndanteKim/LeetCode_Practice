class Solution:
    def canPartitionGrid(self, grid: List[List[int]]) -> bool:
        m, n = len(grid), len(grid[0])
        total = sum(sum(row) for row in grid)
        
        if total % 2:
            return False

        target = (total >> 1)
        col_sum = 0

        for i in range(m - 1):
            col_sum += sum(grid[i])
            if col_sum == target:
                return True
        
        row_sum = 0
        for j in range(n - 1):
            for i in range(m):
                row_sum += grid[i][j]
            if row_sum == target:
                return True

        return False