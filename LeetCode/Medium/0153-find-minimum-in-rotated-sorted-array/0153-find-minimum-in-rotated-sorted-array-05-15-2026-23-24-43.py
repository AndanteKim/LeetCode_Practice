class Solution:
    def findMin(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]

        n = len(nums)
        ans, left, right = float('inf'), 0, n - 1

        if nums[right] > nums[0]:
            return nums[0]

        while left <= right:
            mid = (left + right) >> 1

            if nums[mid] > nums[mid + 1]:
                return nums[mid + 1]
            
            if nums[mid - 1] > nums[mid]:
                return nums[mid]
            
            if nums[mid] > nums[0]:
                left = mid + 1
            else:
                right = mid - 1

        return ans