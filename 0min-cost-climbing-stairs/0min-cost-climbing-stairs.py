class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        @lru_cache(maxsize = None)
        def dp(i: int) -> int:
            if i <= 1:
                return 0
            
            return min(dp(i - 1) + cost[i - 1], dp(i - 2) + cost[i - 2])
            
        n = len(cost)
        return dp(n)