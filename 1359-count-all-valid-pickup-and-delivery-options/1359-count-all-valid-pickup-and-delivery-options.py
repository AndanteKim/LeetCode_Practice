class Solution:
    def countOrders(self, n: int) -> int:
        MOD = 1_000_000_007
        ans = 1
        
        for i in range(1, n + 1):
            ans = ans * i
            
            ans = ans * (2 * i - 1)
            ans %= MOD
        
        return ans