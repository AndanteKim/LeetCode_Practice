class Solution:
    def dp(self, i: int, cost: List[int], memo: Dict[int, int]) -> int:
        if i <= 1:
            return 0
        if i in memo:
            return memo[i]
        
        down_one = cost[i - 1] + self.dp(i - 1, cost, memo)
        down_two = cost[i - 2] + self.dp(i - 2, cost, memo)
        memo[i] = min(down_one, down_two)
        return memo[i]
    
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        memo = dict()
        return self.dp(len(cost), cost, memo)