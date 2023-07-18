class Solution:
    def dp(self, i: int, remain: int, memo: List[List[int]], coins: List[int]) -> int:
        if remain == 0:
            return 1
        if i == len(coins):
            return 0
        
        if memo[i][remain] != -1:
            return memo[i][remain]
        
        if coins[i] > remain:
            memo[i][remain] = self.dp(i + 1, remain, memo, coins)
        else:
            memo[i][remain] = self.dp(i, remain - coins[i], memo, coins) + self.dp(i + 1, remain, memo, coins)
        return memo[i][remain]
    
    def change(self, amount: int, coins: List[int]) -> int:
        memo = [[-1] * (amount + 1) for _ in range(len(coins))]
        
        return self.dp(0, amount, memo, coins)