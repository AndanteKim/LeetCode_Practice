class Solution:
    def findMiddleIndex(self, nums: List[int]) -> int:
        total, leftSum = sum(nums), 0
        
        for i in range(len(nums)):
            if total - nums[i] == 2 * leftSum:
                return i
            leftSum += nums[i]
        return -1