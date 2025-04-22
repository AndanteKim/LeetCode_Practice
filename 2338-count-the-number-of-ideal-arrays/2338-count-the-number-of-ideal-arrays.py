class Solution:
    MOD, MAX_N, MAX_P = 10 ** 9 + 7, 10 ** 4 + 10, 15
    def idealArrays(self, n: int, maxValue: int) -> int:
        sieve = [0] * self.MAX_N

        for i in range(2, self.MAX_N):
            if sieve[i] == 0:
                for j in range(i, self.MAX_N, i):
                    sieve[j] = i
        
        ps = [[] for _ in range(self.MAX_N)]

        for i in range(2, self.MAX_N):
            x = i
            while x > 1:
                p, cnt = sieve[x], 0
                while x % p == 0:
                    x //= p
                    cnt += 1
                ps[i].append(cnt)
        
        c = [[0] * (self.MAX_P + 1) for _ in range(self.MAX_N + self.MAX_P)]
        c[0][0] = 1
        for i in range(1, self.MAX_N + self.MAX_P):
            c[i][0] = 1
            for j in range(1, min(i, self.MAX_P) + 1):
                c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % self.MOD
        
        ans = 0
        for x in range(1, maxValue + 1):
            mul = 1
            for p in ps[x]:
                mul = mul * c[n + p - 1][p] % self.MOD
            ans = (ans + mul) % self.MOD
        return ans

