class Solution:
    def countGoodNumbers(self, n: int) -> int:
        # Use fast exponentiation to calculate x ^ y % mod
        def quick_mul(x: int, y: int) -> int:
            ans, mul = 1, x
            while y > 0:
                if y % 2:
                    ans = ans * mul % self.mod
                mul = mul * mul % self.mod
                y >>= 1
            return ans

        self.mod = 10 ** 9 + 7
        return quick_mul(5, (n + 1) >> 1) * quick_mul(4, n >> 1) % self.mod