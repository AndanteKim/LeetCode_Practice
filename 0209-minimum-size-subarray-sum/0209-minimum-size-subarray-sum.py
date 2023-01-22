class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        if sum(nums) < target: return 0
        
        ans, left, n = float("inf"), 0, len(nums)
        prefix_sum = [0] * (n+1)
        
        for i in range(1, n+1):
            prefix_sum[i] = prefix_sum[i-1] + nums[i-1]
        
        for right in range(1,n+1):
            while prefix_sum[right] - prefix_sum[left] >= target:
                left += 1
                ans = min(ans, right - left + 1)
        return ans