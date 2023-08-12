class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        @lru_cache(maxsize = None)
        def dp(i: int, j: int ) -> int:
            if i >= 0 and j >= 0 and obstacleGrid[i][j]:
                return 0
            if i == 0 and j == 0:
                return 1
            if i < 0 or j < 0:
                return 0
            return dp(i - 1, j) + dp(i, j - 1)
        
        return dp(len(obstacleGrid) - 1, len(obstacleGrid[0]) - 1);