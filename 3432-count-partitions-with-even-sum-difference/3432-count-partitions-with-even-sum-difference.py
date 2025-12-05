class Solution:
    def countPartitions(self, nums: List[int]) -> int:
        total = sum(nums)
        return len(nums) - 1 if total % 2 == 0 else 0