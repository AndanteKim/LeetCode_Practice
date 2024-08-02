class Solution:
    def leftRightDifference(self, nums: List[int]) -> List[int]:
        n = len(nums)
        left_sum, right_sum, ans = [0] * n, [0] * n, [0] * n
        
        for i in range(1, n):
            left_sum[i] = left_sum[i - 1] + nums[i - 1]
            right_sum[n - 1 - i] = right_sum[n - i] + nums[n - i]
            
        for i in range(n):
            ans[i] += abs(left_sum[i] - right_sum[i])
            
        return ans