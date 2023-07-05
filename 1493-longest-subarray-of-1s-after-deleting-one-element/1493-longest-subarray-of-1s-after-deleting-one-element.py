class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        if sum(nums) == n:
            return n - 1
        
        dp = [[0] * 2 for _ in range(n)]
        dp[0][0] = nums[0]
        
        for i in range(1, n):
            if nums[i] == 1:
                dp[i][0], dp[i][1] = dp[i - 1][0] + 1, dp[i - 1][1] + 1
            else:
                dp[i][0], dp[i][1] = 0, dp[i - 1][0]
        
        return max(i for j in dp for i in j)