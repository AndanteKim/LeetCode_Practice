class Solution:
    def countGoodStrings(self, low: int, high: int, zero: int, one: int) -> int:
        def dfs(end: int) -> int:
            # Base case
            if dp[end] != -1:
                return dp[end]
            ans = 0
            if end >= zero:
                ans += dfs(end - zero)
            
            if end >= one:
                ans += dfs(end - one)
            dp[end] = ans % mod
            return dp[end]
        
        # Use dp[i] to record to number of good strings of length i.
        dp, mod = [-1] * (high + 1), 1_000_000_007
        dp[0] = 1

        # Add up the number of strings with each valid length [low ~ high]
        return sum(dfs(end) for end in range(low, high + 1)) % mod