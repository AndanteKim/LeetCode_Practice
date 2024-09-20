class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        def dp(remain: int) -> int:
            # Base case
            if remain < 0:
                return -1
            
            if remain == 0:
                return 0
            
            if memo[remain - 1] != 0:
                return memo[remain - 1]
            
            min_coins = float('inf')
            for coin in coins:
                res = dp(remain - coin)
                if 0 <= res < min_coins:
                    min_coins = res + 1
                    
            memo[remain - 1] = -1 if min_coins == float('inf') else min_coins
            return memo[remain - 1]
        
        if amount < 1:
            return 0
        memo = [0] * amount
        return dp(amount)