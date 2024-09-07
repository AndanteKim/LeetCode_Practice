class Solution:
    def findMin(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1:
            return nums[0]
        left, right = 0, n - 1
        
        while left <= right:
            mid = (left + right) >> 1
            
            if nums[mid] <= nums[-1]:
                right = mid - 1
            else:
                left = mid + 1
                
        return nums[left]