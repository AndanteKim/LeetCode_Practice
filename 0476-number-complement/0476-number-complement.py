class Solution:
    def findComplement(self, num: int) -> int:
        todo, bit = num, 1
        
        while todo:
            # flip the current bit
            num ^= bit
            
            # prepare for the next run
            bit <<= 1
            todo >>= 1
            
        return num