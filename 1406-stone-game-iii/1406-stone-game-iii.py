class Solution:
    def stoneGameIII(self, stoneValue: List[int]) -> str:
        @lru_cache(maxsize = None)
        def f(i: int) -> int:
            if i == n:
                return 0
            
            ans = stoneValue[i] - f(i + 1)
            if i + 2 <= n:
                ans = max(ans, stoneValue[i] + stoneValue[i + 1] - f(i + 2))
            if i + 3 <= n:
                ans = max(ans, stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - f(i + 3))
            return ans
        
        n = len(stoneValue)
        diff = f(0)
        return "Alice" if diff > 0 else "Bob" if diff < 0 else "Tie"