class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        total = sum(nums)
        leftSum = 0
        for i, x in enumerate(nums):
            if leftSum == total - leftSum - x:
                return i
            leftSum += x
        
        return -1