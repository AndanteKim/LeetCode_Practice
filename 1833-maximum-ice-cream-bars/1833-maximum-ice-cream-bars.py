class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        counting = [0] * (max(costs) + 1)
        ans, total = 0, 0
        
        for cost in costs:
            counting[cost] += 1
            ans += 1
            total += cost
        
        i = len(counting) - 1
        
        while i > 0 and total > coins:
            if counting[i] == 0:
                i -= 1
            else:
                total -= i
                counting[i] -= 1
                ans -= 1
        
        return ans
                