class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        count, mx, mn = [0] * (10 ** 5 + 1), float('-inf'), float('inf')

        for cost in costs:
            count[cost] += 1
            mx = max(mx, cost)
            mn = min(mn, cost)

        ans = 0
        for cost in range(mn, mx + 1):
            if coins < cost * count[cost]:
                ans += coins // cost
                break
            coins -= cost * count[cost]
            ans += count[cost]

        return ans