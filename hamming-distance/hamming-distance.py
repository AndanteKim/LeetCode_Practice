class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        xor, count = x ^ y, 0
        
        while xor > 0:
            count += xor & 1
            xor >>= 1
        
        return count