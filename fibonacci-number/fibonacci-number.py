class Solution:
    def fib(self, n: int) -> int:
        def dp(remain: int) -> int:
            # Base case
            if remain < 2:
                return remain
            if memo[remain] != -1:
                return memo[remain]
            
            memo[remain] = dp(remain - 1) + dp(remain - 2)
            return memo[remain]
            
        memo = [-1] * (n + 1)
        return dp(n)