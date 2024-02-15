class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        n = len(nums)
        if n < 3:
            return -1
        
        nums.sort()
        prefix_sum = [0] * (n + 1)
        
        for i in range(1, n + 1):
            prefix_sum[i] = prefix_sum[i - 1] + nums[i - 1] 
        
        for i in range(n - 1, 0, -1):
            if nums[i] < prefix_sum[i]:
                return prefix_sum[i] + nums[i]
        
        return -1