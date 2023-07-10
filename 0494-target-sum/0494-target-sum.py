class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        total = sum(nums)
        dp = [0] * (2 * total + 1)
        dp[nums[0] + total] = 1
        dp[-nums[0] + total] += 1
        
        for i in range(1, len(nums)):
            nxt = [0] * (2 * total + 1)
            for s in range(-total, total + 1):
                if dp[s + total] > 0:
                    nxt[s + total + nums[i]] += dp[s + total]
                    nxt[s + total - nums[i]] += dp[s + total]
            dp = nxt
        
        return 0 if abs(target) > total else dp[target + total]
        