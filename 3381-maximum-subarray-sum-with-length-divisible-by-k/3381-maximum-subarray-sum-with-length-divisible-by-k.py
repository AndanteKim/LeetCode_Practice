class Solution:
    def maxSubarraySum(self, nums: List[int], k: int) -> int:
        n, prefix_sum = len(nums), 0
        ans = float('-inf')
        k_sum = [float('inf')] * k
        k_sum[k - 1] = 0

        for i in range(n):
            prefix_sum += nums[i]
            ans = max(ans, prefix_sum - k_sum[i % k])
            k_sum[i % k] = min(k_sum[i % k], prefix_sum)

        return ans