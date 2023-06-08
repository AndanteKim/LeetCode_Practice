class Solution:
    def isMajorityElement(self, nums: List[int], target: int) -> bool:
        
        half = len(nums) / 2
        right = bisect_right(nums, target)
        left = bisect_left(nums, target)
        
        return True if right - left > half else False