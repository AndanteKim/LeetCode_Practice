class Solution:
    def minCostII(self, costs: List[List[int]]) -> int:
        n = len(costs)
        if n == 0:
            return 0
        k = len(costs[0])
        
        for house in range(1, n):
            for color in range(k):
                best = float('inf')
                for previous_color in range(k):
                    if color == previous_color:
                        continue
                    best = min(best, costs[house - 1][previous_color])
                costs[house][color] += best
        
        return min(costs[-1])