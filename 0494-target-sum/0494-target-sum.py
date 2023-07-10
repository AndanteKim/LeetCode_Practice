class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        total, n = sum(nums), len(nums)
        dp = [[0] * (2 * total + 1) for _ in range(n)]
        dp[0][nums[0] + total] = 1
        dp[0][-nums[0] + total] += 1
        
        for i in range(1, n):
            for s in range(-total, total + 1):
                if dp[i - 1][s + total] > 0:
                    dp[i][s + total + nums[i]] += dp[i - 1][s + total]
                    dp[i][s + total - nums[i]] += dp[i - 1][s + total]
        
        return 0 if abs(target) > total else dp[n - 1][target + total]
                