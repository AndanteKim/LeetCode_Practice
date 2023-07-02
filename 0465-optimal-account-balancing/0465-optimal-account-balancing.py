class Solution:
    def dfs(self, total_mask: int, memo: List[int], balance_list: List[int]) -> int:
        if memo[total_mask] != -1:
            return memo[total_mask]
        balance_sum, ans = 0, 0
        
        for i in range(12):
            curr_bit = 1 << i
            if total_mask & curr_bit:
                balance_sum += balance_list[i]
                ans = max(ans, self.dfs(total_mask ^ curr_bit, memo, balance_list))
        memo[total_mask] = ans + (balance_sum == 0)
        return memo[total_mask]
    
    def minTransfers(self, transactions: List[List[int]]) -> int:
        balance_list = [0] * 12
        for start, end, amount in transactions:
            balance_list[start] += amount
            balance_list[end] -= amount
        
        memo = [-1] * (1 << 12)
        memo[0] = 0
        
        return 12 - self.dfs((1 << 12) - 1, memo, balance_list)