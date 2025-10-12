class Solution:
    def quickmul(self, x: int, y: int) -> int:
        res, curr = 1, x % self.mod
        while y:
            if y & 1:
                res = res * curr % self.mod
            y >>= 1
            curr = curr * curr % self.mod
        return res

    def magicalSum(self, m: int, k: int, nums: List[int]) -> int:
        self.mod, n = 10 ** 9 + 7, len(nums)

        fac = [1] * (m + 1)
        for i in range(1, m + 1):
            fac[i] = fac[i - 1] * i % self.mod

        ifac = [1] * (m + 1)
        for i in range(2, m + 1):
            ifac[i] = self.quickmul(i, self.mod - 2)
        for i in range(2, m + 1):
            ifac[i] = ifac[i - 1] * ifac[i] % self.mod
        
        nums_power = [[1] * (m + 1) for _ in range(n)]

        for i in range(n):
            for j in range(1, m + 1):
                nums_power[i][j] = nums_power[i][j - 1] * nums[i] % self.mod
        
        f = [
            [[[0] * (k + 1) for _ in range(m * 2 + 1)] for _ in range(m + 1)]
            for _ in range(n)
        ]

        for j in range(m + 1):
            f[0][j][j][0] = nums_power[0][j] * ifac[j] % self.mod

        for i in range(n - 1):
            for j in range(m + 1):
                for p in range(m * 2 + 1):
                    for q in range(k + 1):
                        if f[i][j][p][q] == 0:
                            continue
                        q2 = (p % 2) + q
                        if q2 > k:
                            break
                        for r in range(m - j + 1):
                            p2 = (p >> 1) + r
                            if p2 > m * 2:
                                continue
                            f[i + 1][j + r][p2][q2] = (
                                f[i + 1][j + r][p2][q2]
                                + f[i][j][p][q]
                                * nums_power[i + 1][r]
                                % self.mod
                                * ifac[r]
                                % self.mod
                            ) % self.mod
        ans = 0

        for p in range(m * 2 + 1):
            for q in range(k + 1):
                if bin(p).count("1") + q == k:
                    ans = (ans + f[n - 1][m][p][q] * fac[m] % self.mod) % self.mod
        
        return ans