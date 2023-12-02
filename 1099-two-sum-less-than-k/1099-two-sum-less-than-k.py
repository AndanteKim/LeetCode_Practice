class Solution:
    def twoSumLessThanK(self, nums: List[int], k: int) -> int:
        nums.sort()
        ans = -1
        for i in range(len(nums)):
            j = bisect_left(nums, k - nums[i], i + 1) - 1
            if i < j:
                ans = max(ans, nums[i] + nums[j])
        
        return ans