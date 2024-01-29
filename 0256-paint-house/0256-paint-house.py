class Solution:
    def minCost(self, costs: List[List[int]]) -> int:
        
        # prev_color - 0 := red, 1:= blue, 2:= green
        @lru_cache(maxsize = None)
        def dp(i: int, prev_color: int) -> int:
            if i == n:
                return 0
            
            min_cost = float('inf')
            for color_idx in range(3):
                if color_idx == prev_color:
                    continue
                min_cost = min(min_cost, costs[i][color_idx] + dp(i + 1, color_idx))
            return min_cost
        
        n = len(costs)
        return dp(0, -1)