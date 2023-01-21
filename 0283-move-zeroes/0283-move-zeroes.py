class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        left, right, n = 0, 1, len(nums)
        
        while right < n:
            if nums[left] == 0 and nums[right] != 0:
                nums[left], nums[right] = nums[right], nums[left]
            while nums[left] != 0 and left < right:
                left += 1
            right += 1
        
            