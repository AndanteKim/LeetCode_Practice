class Solution:
    def bestClosingTime(self, customers: str) -> int:
        n = len(customers)
        no_cnt, yes_cnt = [0] * (n + 1), [0] * (n + 1)
        no_sum, yes_sum = 0, 0
        
        for i in range(n):
            no_sum += customers[i] == 'N'
            no_cnt[i + 1] = no_sum
            
        for i in range(n - 1, -1, -1):
            yes_sum += customers[i] == 'Y'
            yes_cnt[i] = yes_sum
        
        ans, current = float('inf'), float('inf')
        for i in range(n + 1):
            if current > no_cnt[i] + yes_cnt[i]:
                ans = i
                current = no_cnt[i] + yes_cnt[i]
        
        return ans