class Solution:
    def maxRotateFunction(self, nums: List[int]) -> int:
        f, n, num_sum = 0, len(nums), sum(nums)

        for i, num in enumerate(nums):
            f += i * num
        
        ans = f
        for i in range(n - 1, 0, -1):
            f = f + num_sum - n * nums[i]
            ans = max(ans, f)
        
        return ans