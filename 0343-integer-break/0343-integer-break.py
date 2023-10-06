class Solution:
    def integerBreak(self, n: int) -> int:
        @lru_cache(maxsize = None)
        def dp(num: int) -> int:
            if num <= 3:
                return num
            
            ans = num
            for i in range(2, num):
                ans = max(ans, i * dp(num - i))
            
            return ans
                
        if n <= 3:
            return n - 1
        return dp(n)