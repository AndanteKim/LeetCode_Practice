class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        i, j, n = 0, 0, len(nums)
        while j < n:
            if i != j and nums[i] == 0 and nums[j] != 0:
                nums[i], nums[j] = nums[j], nums[i]
                i += 1
            if nums[i] != 0:
                i += 1
            j += 1