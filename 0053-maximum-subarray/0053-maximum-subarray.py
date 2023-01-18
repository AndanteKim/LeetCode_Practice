class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        cur_max, max_sum, total = 0, nums[0], 0
        
        for num in nums:
            cur_max = max(cur_max, 0) + num
            max_sum = max(max_sum, cur_max)
            
        return max_sum