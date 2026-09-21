class Solution:
    def resultArray(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        dp, ans = [0] * k, [0] * k

        for i, num in enumerate(nums):
            ndp = [0] * k   # Current state (rolling array).
            ndp[num % k] += 1

            for r in range(k):
                ndp[(r * num) % k] += dp[r]
            
            dp = ndp

            for r in range(k):
                ans[r] += dp[r]

        return ans
        