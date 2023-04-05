class Solution:
    def minimizeArrayValue(self, nums: List[int]) -> int:
        ans, prefix_sum = 0, 0
        
        for i in range(len(nums)):
            prefix_sum += nums[i]
            ans = max(ans, ceil(prefix_sum / (i + 1)))
        
        return ans