class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        @lru_cache(maxsize = None)
        def dp(i: int) -> int:
            if i <= 1:
                return 0
            
            one_step = cost[i - 1] + dp(i - 1)
            two_steps = cost[i - 2] + dp(i - 2)
            return min(one_step, two_steps)
            
        n = len(cost)
        return dp(n)