class Solution:
    def rangeBitwiseAnd(self, left: int, right: int) -> int:
        # Brian Kernighan's algorithm
        while left < right:
            # Turn off the rightmost 1-bit
            right &= (right - 1)
        return right