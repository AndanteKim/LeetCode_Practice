class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        # difference between two numbers (x and y) whih were seen only once
        bitmask = 0
        for num in nums:
            bitmask ^= num
            
        # rightmost 1-bit diff between x and y
        diff = bitmask & (-bitmask)
        
        x = 0
        for num in nums:
            # bitmask which will contain only x
            if num & diff:
                x ^= num
        
        return [x, bitmask ^ x]