class Solution:
    MOD = 1_000_000_007
    def power(self, base: int, exponent: int) -> int:
        res = 1
        while exponent > 0:
            if exponent & 1:
                res = (res * base) % self.MOD
            exponent >>= 1
            base = (base * base) % self.MOD
        return res
            
    def precalculate_factorials(self, n: int) -> None:
        self.factorial, self.inv_factorial = [1] * (n + 1), [1] * (n + 1)
        for i in range(1, n + 1):
            self.factorial[i] = (self.factorial[i - 1] * i) % self.MOD
            # Fermat's Little Theorem
            self.inv_factorial[i] = self.power(self.factorial[i], self.MOD - 2)
        
    def numMusicPlaylists(self, n: int, goal: int, k: int) -> int:
        self.precalculate_factorials(n)
        sign, ans = 1, 0
        
        for i in range(n, k - 1, -1):
            temp = self.power(i - k, goal - k)
            temp = (temp * self.inv_factorial[n - i]) % self.MOD
            temp = (temp * self.inv_factorial[i - k]) % self.MOD
            
            ans = (ans + sign * temp + self.MOD) % self.MOD
            sign *= -1
        return (self.factorial[n] * ans) % self.MOD