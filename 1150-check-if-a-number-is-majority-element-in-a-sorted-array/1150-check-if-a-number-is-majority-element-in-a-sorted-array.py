class Solution:
    def isMajorityElement(self, nums: List[int], target: int) -> bool:
        left, right = bisect_left(nums, target), bisect_right(nums, target)

        return True if right - left > (len(nums) >> 1) else False