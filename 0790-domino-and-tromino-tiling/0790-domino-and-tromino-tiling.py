class Solution:
    def numTilings(self, n: int) -> int:
        mod = 1_000_000_007
        if n <= 2:
            return n
        
        # f[k] := number of ways "fully cover a board" of width k
        # p[k] := number of ways "partially cover a board" of width k
        f, p = [0] * (n + 1), [0] * (n + 1)
        f[1], f[2], p[2] = 1, 2, 1
        
        for k in range(3, n + 1):
            f[k] = (f[k - 1] + f[k - 2] + 2 * p[k - 1]) % mod
            p[k] = (p[k - 1] + f[k - 2]) % mod
        
        return f[n]
        