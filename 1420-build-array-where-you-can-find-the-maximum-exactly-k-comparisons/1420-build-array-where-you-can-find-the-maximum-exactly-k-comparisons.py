class Solution:
    def numOfArrays(self, n: int, m: int, k: int) -> int:
        @lru_cache(maxsize = None)
        def dp(i: int, max_so_far: int, remain: int) -> int:
            if i == n:
                if remain == 0:
                    return 1
                return 0
            
            ans = (max_so_far * dp(i + 1, max_so_far, remain)) % MOD
            for num in range(max_so_far + 1, m + 1):
                ans = (ans + dp(i + 1, num, remain - 1)) % MOD
            return ans
        
        MOD = 10 ** 9 + 7
        return dp(0, 0, k)
        
        
        