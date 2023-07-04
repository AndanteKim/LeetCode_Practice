class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        ans = 0
        
        for shift in range(32):
            bit_sum = 0
            for num in nums:
                bit_sum += (num >> shift) & 1
            
            loner_bit = bit_sum % 3
            ans = ans | (loner_bit << shift)
        
        if ans >= (1 << 31):
            ans = ans - (1 << 32)
        
        return ans