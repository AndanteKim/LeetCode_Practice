class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        if n <= 0:
            return False

        x = log(n) / (2 * log(2))
        return int(x) == x