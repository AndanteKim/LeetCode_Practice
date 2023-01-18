class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        n = len(nums)
        right_max = [0] * n
        right_max[n-1], suffix_sum = nums[n-1], nums[n-1]
        for i in range(n-2, -1, -1):
            suffix_sum += nums[i]
            right_max[i] = max(right_max[i+1], suffix_sum)
            
        max_sum, special_sum = nums[0], nums[0]
        suffix_sum, curMax = 0, 0
        for i in range(n):
            curMax = max(curMax, 0) + nums[i]
            max_sum = max(max_sum, curMax)
            suffix_sum += nums[i]
            if i + 1 < n:
                special_sum = max(special_sum, suffix_sum + right_max[i+1])
            
        return max(max_sum, special_sum)
        