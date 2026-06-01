class Solution:
    def minimumCost(self, cost: List[int]) -> int:
        if len(cost) <= 2:
            return sum(cost)

        cost.sort(reverse = True)
        ans, n, j = 0, len(cost), 0

        for i in range(0, n - 2, 3):
            ans += cost[i] + cost[i + 1]
            j = i + 3
        
        for i in range(j, n):
            ans += cost[i]
        
        return ans