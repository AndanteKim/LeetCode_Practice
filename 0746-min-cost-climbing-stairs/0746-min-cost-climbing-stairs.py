class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        # bottom-up
        n = len(cost)
        min_cost = [0] * (n + 1)
        
        for i in range(2, n + 1):
            one_step = min_cost[i - 1] + cost[i - 1]
            two_steps = min_cost[i - 2] + cost[i - 2]
            min_cost[i] = min(one_step, two_steps)
            
        return min_cost[-1]