class Solution:
    def climbStairs(self, n: int) -> int:
        @lru_cache(maxsize = None)
        def dfs(remain: int) -> int:
            if remain <= 0:
                return 1 if remain == 0 else 0
            
            return dfs(remain - 1) + dfs(remain - 2)
        return dfs(n)