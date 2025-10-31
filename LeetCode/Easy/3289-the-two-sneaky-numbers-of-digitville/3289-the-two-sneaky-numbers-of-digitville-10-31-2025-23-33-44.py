class Solution:
    def getSneakyNumbers(self, nums: List[int]) -> List[int]:
        n, y = len(nums) - 2, 0

        for x in nums:
            y ^= x
        
        for i in range(n):
            y ^= i
        
        low_bit = y & -y
        x1 = x2 = 0

        for x in nums:
            if x & low_bit:
                x1 ^= x
            else:
                x2 ^= x
        
        for i in range(n):
            if i & low_bit:
                x1 ^= i
            else:
                x2 ^= i

        return [x1, x2]
