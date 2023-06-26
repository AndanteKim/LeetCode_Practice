class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        @lru_cache(maxsize = None)
        def dfs(i: int, n: int) -> int:
            if i >= n - 1:
                return 0
            return min(cost[i] + dfs(i + 1, n), cost[i + 1] + dfs(i + 2, n))
        
        return dfs(0, n)