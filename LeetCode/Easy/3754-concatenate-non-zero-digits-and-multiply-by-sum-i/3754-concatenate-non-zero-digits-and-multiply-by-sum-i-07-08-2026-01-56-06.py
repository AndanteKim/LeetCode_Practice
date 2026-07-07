class Solution:
    def sumAndMultiply(self, n: int) -> int:
        x, total, digit = 0, 0, 0

        while n > 0:
            d = n % 10
            if d == 0:
                n //= 10
                continue
            x += (10 ** digit) * d
            digit += 1
            total += d
            n //= 10

        return x * total