class Solution:
    def getDescentPeriods(self, prices: List[int]) -> int:
        ans, stack = 0, []

        for price in prices:
            if stack and stack[-1] - price != 1:
                ans += (len(stack) * (len(stack) + 1) >> 1)
                stack.clear()
            stack.append(price)

        if len(stack) > 0:
            ans += (len(stack) * (len(stack) + 1) >> 1)
        return ans