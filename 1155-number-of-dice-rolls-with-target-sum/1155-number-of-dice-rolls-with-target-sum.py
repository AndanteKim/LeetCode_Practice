class Solution:
    MOD = int(10 ** 9 + 7)
    def dp(self, memo: List[List[int]], dice_idx: int, n: int, curr_sum: int, target: int, k: int) -> int:
        if (dice_idx == n):
            return int(curr_sum == target)
        
        if memo[dice_idx][curr_sum] != -1:
            return memo[dice_idx][curr_sum]
        
        ways = 0
        for i in range(1, min(k, target - curr_sum) + 1):
            ways = (ways + self.dp(memo, dice_idx + 1, n, curr_sum + i, target, k)) % self.MOD
        
        memo[dice_idx][curr_sum] = ways
        return memo[dice_idx][curr_sum]
    
    def numRollsToTarget(self, n: int, k: int, target: int) -> int:
        memo = [[-1] * (target + 1) for _ in range(n + 1)]
        return self.dp(memo, 0, n, 0, target, k);
        