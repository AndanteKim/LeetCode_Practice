class Solution:
    def minimumOneBitOperations(self, n: int) -> int:
        ans = n

        ans ^= ans >> 16
        ans ^= ans >> 8
        ans ^= ans >> 4
        ans ^= ans >> 2
        ans ^= ans >> 1

        return ans