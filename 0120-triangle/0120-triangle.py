class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        m = len(triangle)
        if m == 1:
            return triangle[0][0]
        
        dp = [[float('inf')] * len(triangle[i]) for i in range(m)]
        dp[0][0] = triangle[0][0]
        for i in range(m - 1):
            for j in range(len(triangle[i])):
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + triangle[i + 1][j])
                dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + triangle[i + 1][j + 1])
        
        return min(dp[-1])