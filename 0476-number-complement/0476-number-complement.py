class Solution:
    def findComplement(self, num: int) -> int:
        # n is a length of num in binary representation
        n = floor(log2(num)) + 1
        
        # The bitmask has the same length as num and contains only ones 1...1
        bitmask = (1 << n) - 1
        
        # Flip all bits
        return bitmask ^ num