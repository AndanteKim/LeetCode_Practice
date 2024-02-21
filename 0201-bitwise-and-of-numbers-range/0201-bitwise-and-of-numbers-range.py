class Solution:
    def rangeBitwiseAnd(self, left: int, right: int) -> int:
        while left < right:
            # turn off the rightmost 1-bit
            right = right & (right - 1)
            
        return left & right