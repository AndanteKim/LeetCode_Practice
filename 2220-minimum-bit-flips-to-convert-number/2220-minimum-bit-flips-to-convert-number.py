class Solution:
    def minBitFlips(self, start: int, goal: int) -> int:
        # Xor to find differing bits
        ans, xor_res = 0, start ^ goal
        
        # Brian Kernighans algorithm to count 1s
        while xor_res:
            # Clear the lowest set bit
            xor_res &= xor_res - 1
            ans += 1
            
        return ans