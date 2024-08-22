class Solution:
    def findComplement(self, num: int) -> int:
        ans, bitwise = 0, 1
        
        while bitwise < num:
            if not num & bitwise:
                ans += bitwise
                
            bitwise <<= 1
            
        return ans
        