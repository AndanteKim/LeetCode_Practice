class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # Top-Down Dynamic programming
        def dp(i: int, left: int) -> int:
            if i == n or left == 0:
                return 0
            
            # If we saved the subproblem result
            if memo[i][left] != -1:
                return memo[i][left]
            
            # start choosing no transaction
            profit1 = dp(i + 1, left)
            
            # choose buying or selling it.
            profit2, bought = 0, (left % 2 == 0)
            if bought:
                profit2 = -prices[i] + dp(i + 1, left - 1)
            else:
                profit2 = prices[i] + dp(i + 1, left - 1)
                
            memo[i][left] = max(profit1, profit2)
            return memo[i][left]
                
        
        n = len(prices)
        memo = [[-1] * 5 for i in range(n + 1)]
        # We set 4 times left due to at most two transactions(buy -> sell -> buy -> sell)
        return dp(0, 4)