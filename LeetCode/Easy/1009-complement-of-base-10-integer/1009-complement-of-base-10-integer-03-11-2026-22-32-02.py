class Solution:
    def bitwiseComplement(self, n: int) -> int:
        if n == 0:
            return 1

        ans, i = 0, 0
        while n > 0:
            ans += (1 << i) * ((n % 2) ^ 1)
            i += 1
            n >>= 1

        return ans