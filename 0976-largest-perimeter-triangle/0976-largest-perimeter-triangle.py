class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        length = len(nums)
        nums.sort()
        for i in range(length-3, -1, -1):
            if nums[i] + nums[i+1] > nums[i+2]:
                return nums[i] + nums[i+1] + nums[i+2]
            
        return 0