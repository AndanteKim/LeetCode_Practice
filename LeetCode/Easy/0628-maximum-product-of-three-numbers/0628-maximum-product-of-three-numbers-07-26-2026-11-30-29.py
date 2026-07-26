class Solution:
    def maximumProduct(self, nums: List[int]) -> int:
        nums.sort()

        if nums[-1] <= 0:
            return nums[-3] * nums[-2] * nums[-1]
        
        n = len(nums)
        first = nums[0] * nums[1] * nums[-1]
        second = nums[-3] * nums[-2] * nums[-1]
        
        return second if first < second else first