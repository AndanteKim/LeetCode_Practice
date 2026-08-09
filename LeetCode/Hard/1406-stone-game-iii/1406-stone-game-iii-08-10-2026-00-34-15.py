class Solution:
    def stoneGameIII(self, stoneValue: List[int]) -> str:
        @lru_cache(maxsize = None)
        def dp(i: int) -> int:
            if i == n:
                return 0

            if memo[i] != -1:
                return memo[i]

            max_diff = stoneValue[i] - dp(i + 1)

            if i < n - 1:
                max_diff = max(max_diff, stoneValue[i] + stoneValue[i + 1] - dp(i + 2))
            
            if i < n - 2:
                max_diff = max(max_diff, stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - dp(i + 3))

            memo[i] = max_diff
            return max_diff

        n = len(stoneValue)
        memo = [-1] * n
        return "Alice" if dp(0) > 0 else "Bob" if dp(0) < 0 else "Tie"