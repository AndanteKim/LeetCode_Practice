class Solution:
    def numWays(self, steps: int, arrLen: int) -> int:
        @lru_cache(maxsize = None)
        def dp(curr: int, remain: int) -> int:
            nonlocal arrLen
            if remain == 0:
                if curr == 0:
                    return 1
                return 0
            
            ans = dp(curr, remain - 1)
            if curr > 0:
                ans = (ans + dp(curr - 1, remain - 1)) % mod
            if curr < arrLen - 1:
                ans = (ans + dp(curr + 1, remain - 1)) % mod
            return ans
        
        mod = 10 ** 9 + 7
        return dp(0, steps)