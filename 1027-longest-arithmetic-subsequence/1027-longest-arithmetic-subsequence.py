class Solution:
    def longestArithSeqLength(self, nums: List[int]) -> int:
        ans, n = 2, len(nums)
        
        dp = [[0] * 2000 for _ in range(n)]
        for i in range(n):
            for j in range(i):
                diff = nums[i] - nums[j] + 1000
                dp[i][diff] = max(2, dp[j][diff] + 1)
                ans = max(ans, dp[i][diff])
        
        return ans