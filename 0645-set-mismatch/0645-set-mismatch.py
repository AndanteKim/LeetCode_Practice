class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        diff, sq_diff = 0, 0
        
        for i in range(0, len(nums)):
            diff += (i + 1) - nums[i]
            
            sq_diff += (i + 1) ** 2 - nums[i] ** 2
            
        sum = sq_diff // diff
        
        return [(sum - diff) >> 1, (sum + diff) >> 1]