class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        prev = -1

        while n > 0:
            if prev == n % 2:
                return False
            prev = n % 2
            n >>= 1

        return True