class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        @lru_cache(maxsize = None)
        def dp(i: int, two_steps: bool) -> int:
            if i >= n:
                return 0
            if two_steps:
                return min(cost[i] + dp(i + 1, False), cost[i] + dp(i + 2, True))
            
            return min(cost[i] + dp(i + 1, False), cost[i] + dp(i + 2, True), dp(i + 1, True))
        
        n = len(cost)
        return dp(0, False)