class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        one_step, two_steps = 0, 0
        
        for i in range(2, n + 1):
            temp = one_step
            one_step = min(one_step + cost[i - 1], two_steps + cost[i - 2])
            two_steps = temp
            
        return one_step
        