class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if not nums:
            return [-1, -1]
        first, last = bisect_left(nums, target), bisect_right(nums, target)
        
        return [-1, -1] if first >= len(nums) or nums[first] != target else [first, last - 1]