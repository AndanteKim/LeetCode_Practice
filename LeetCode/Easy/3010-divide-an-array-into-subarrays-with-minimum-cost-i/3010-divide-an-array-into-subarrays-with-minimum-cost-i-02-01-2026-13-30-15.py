class Solution:
    def minimumCost(self, nums: List[int]) -> int:
        min_subarr, n = float('inf'), len(nums)
        for i in range(1, n - 1):
            for j in range(i + 1, n):
                min_subarr = min(min_subarr, nums[i] + nums[j])

        return nums[0] + min_subarr