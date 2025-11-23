class Solution:
    def maxSumDivThree(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [[float('-inf')] * 3 for _ in range(n + 1)]

        dp[0][0] = 0

        for i in range(n):
            x = nums[i]
            for j in range(3):
                dp[i + 1][j] = max(x + dp[i][(j + x) % 3], dp[i][j])

        return dp[n][0]