class Solution:
    MOD = 1_000_000_007

    def mul(self, a: List[List[int]], b: List[List[int]]) -> List[List[int]]:
        n, m = len(a), len(b[0])
        ans = [[0] * m for _ in range(n)]

        for i in range(n):
            for k in range(len(a[0])):
                r = a[i][k]
                if r == 0:
                    continue
                for j in range(m):
                    ans[i][j] = (ans[i][j] + r * b[k][j]) % self.MOD

        return ans

    def powMul(self, base: List[List[int]], exp: int, ans: List[List[int]]) -> List[List[int]]:
        while exp > 0:
            if exp & 1:
                ans = self.mul(ans, base)
            base = self.mul(base, base)
            exp >>= 1
        
        return ans


    def zigZagArrays(self, n: int, l: int, r: int) -> int:
        m = r - l + 1
        if n == 1:
            return m

        size = 2 * m
        u = [[0] * size for _ in range(size)]
        for i in range(m):
            for j in range(i):
                u[i][j + m] = 1
            
            for j in range(i + 1, m):
                u[i + m][j] = 1

        dp = [[1] * size]
        dp = self.powMul(u, n - 1, dp)
        ans = 0

        for i in range(size):
            ans = (ans + dp[0][i]) % self.MOD
        
        return ans