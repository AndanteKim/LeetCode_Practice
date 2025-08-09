class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        curr = 1

        while curr <= n:
            if curr == n:
                return True
            curr <<= 1

        return False