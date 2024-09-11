class Solution:
    def minBitFlips(self, start: int, goal: int) -> int:
        # XOR to find differing bits
        xor_res = start ^ goal
        ans = 0
        
        # Count the number of 1s in xor_result (differing bits)
        while xor_res:
            ans += xor_res & 1 # Increment if the last bit is 1
            xor_res >>= 1   # Shift right to process the next bit
            
        return ans
        
        