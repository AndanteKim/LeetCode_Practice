class Solution:
    def minPairSum(self, nums: List[int]) -> int:
        nums.sort()
        max_sum, n = 0, len(nums)
        
        for i in range(n // 2 + 1):
            max_sum = max(max_sum, nums[i] + nums[n - 1 - i])
        
        return max_sum