class Solution:
    def numTilings(self, n: int) -> int:
        mod = 1_000_000_007

        # base case
        if n <= 2:
            return n

        # f[k]: the number of ways to "fully cover a board" of width k
        f = [0] * (n + 1)

        # p[k]: the number of ways to "partially cover a board" of width k
        p = [0] * (n + 1)

        # Initialize f and p with results for the base case scenarios
        f[1], f[2], p[2] = 1, 2, 1

        for k in range(3, n + 1):
            f[k] = (f[k - 1] + f[k - 2] + 2 * p[k - 1]) % mod
            p[k] = (p[k - 1] + f[k - 2]) % mod
        
        return f[n]