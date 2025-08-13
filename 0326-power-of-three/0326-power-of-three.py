class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        if n <= 0:
            return False

        x = int(log2(n) // log2(3))
        return 3 ** x == n