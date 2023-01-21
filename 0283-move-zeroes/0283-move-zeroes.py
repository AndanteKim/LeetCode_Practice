class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        lastNonZeroFoundAt = 0
        
        for curr in range(len(nums)):
            if nums[curr] != 0:
                nums[lastNonZeroFoundAt], nums[curr] = nums[curr], nums[lastNonZeroFoundAt]
                lastNonZeroFoundAt += 1
        
            