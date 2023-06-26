class Solution:
    def dp(self, i: int, memo: Dict[int, int], cost: List[int]) -> int:
        if i <= 1:
            return 0
        
        if i in memo:
            return memo[i]
        
        memo[i] = min(self.dp(i - 1, memo, cost) + cost[i - 1], self.dp(i - 2, memo, cost) + cost[i - 2])
        return memo[i]
    
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        memo = dict()
        return self.dp(len(cost), memo, cost)