class Solution:
    def numTilings(self, n: int) -> int:
        MOD = 1_000_000_007
        if n <= 2:
            return n
        f_prev, f_curr, p_curr = 1, 2, 1
        
        for k in range(3, n + 1):
            tmp = f_curr
            f_curr = (f_prev + f_curr + 2 * p_curr) % MOD
            p_curr = (p_curr + f_prev) % MOD
            f_prev = tmp
        
        return f_curr
        