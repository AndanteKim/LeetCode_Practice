class Solution:
    def countOrders(self, n: int) -> int:
        MOD, ans = 1_000_000_007, 1
        
        for i in range(1, 2 * n + 1):
            ans *= i
            
            if not i % 2:
                ans //= 2
            ans %= MOD
            
        return ans
        