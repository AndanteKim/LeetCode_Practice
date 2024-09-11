class Solution:
    def reverseBits(self, n: int) -> int:
        ans, power = 0, 31
        
        while n:
            ans += (n & 1) << power
            n >>= 1
            
            power -= 1
            
        return ans