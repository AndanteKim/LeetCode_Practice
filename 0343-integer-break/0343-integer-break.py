class Solution:
    def integerBreak(self, n: int) -> int:
        @lru_cache(maxsize = None)
        def dp(remain: int, product: int) -> int:
            if remain <= 1:
                return product
            
            mx = 1
            for i in range(1, remain + 1):
                mx = max(mx, dp(remain - i, product * i))
                    
            return mx
        
        if n == 2:
            return 1
        if n == 3:
            return 2
        
        return dp(n, 1)