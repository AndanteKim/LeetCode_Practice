class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        cur_max, cur_min, sum, max_sum, min_sum = 0, 0, 0, nums[0], nums[0]
        
        for num in nums:
            cur_max = max(cur_max, 0) + num
            max_sum = max(max_sum, cur_max)
            cur_min = min(cur_min, 0) + num
            min_sum = min(min_sum, cur_min)
            sum += num;
        
        return max_sum if sum == min_sum else max(max_sum, sum - min_sum)