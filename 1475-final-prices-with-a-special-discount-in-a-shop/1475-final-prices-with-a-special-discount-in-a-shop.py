class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:
        n = len(prices)
        stack, ans = [], [0]*n
        
        for i in range(n):
            while stack and prices[stack[-1]] >= prices[i]:
                j = stack.pop()
                ans[j] = prices[j] - prices[i]
            stack.append(i)
        
        while stack:
            i = stack.pop()
            ans[i] = prices[i]
        
        return ans