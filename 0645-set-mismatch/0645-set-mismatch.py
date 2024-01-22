class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        # xor0 := missing, xor1: duplicate
        xor, xor0, xor1 = 0, 0, 0
        
        for n in nums:
            xor ^= n
            
        for i in range(1, len(nums) + 1):
            xor ^= i
            
        rightmostbit = xor & ~(xor - 1)
                                     
        for n in nums:
            if (n & rightmostbit) != 0:
                xor1 ^= n
            else:
                xor0 ^= n
                
        for i in range(1, len(nums) + 1):
            if (i & rightmostbit) != 0:
                xor1 ^= i
            else:
                xor0 ^= i
                
        for i in range(0, len(nums)):
            if nums[i] == xor0:
                return [xor0, xor1]
            
        return [xor1, xor0]
        