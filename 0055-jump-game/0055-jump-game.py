class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n = len(nums)
        dp = [0] * n
        dp[n - 1] = 1
        
        for i in range(n - 2, -1, -1):
            furthest = min(i + nums[i], n - 1)
            for nxt in range(i + 1, furthest + 1):
                if dp[nxt] == 1:
                    dp[i] = 1
                    break
        
        return dp[0] == 1
        
        