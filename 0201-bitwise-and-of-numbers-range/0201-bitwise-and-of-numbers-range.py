class Solution:
    def rangeBitwiseAnd(self, left: int, right: int) -> int:
        shift = 0
        
        # Find the common 1-bits
        while left < right:
            left >>= 1
            right >>= 1
            shift += 1
        
        return left << shift     