class Solution:
    def maxSumAfterOperation(self, nums: List[int]) -> int:
        n = len(nums)

        # Arrays to store the maximum sum of subarrays ending before and starting after each element
        max_left, max_right = [0] * n, [0] * n
        max_left[0] = 0

        for i in range(1, n):
            # Compute max_left[i]: the maximum subarray sum ending just before nums[i]
            max_left[i] = max(max_left[i - 1] + nums[i - 1], 0)

        for i in range(n - 2, -1, -1):
            # Compute max_right[i]: the maximum subarray sum starting just after nums[i]
            max_right[i] = max(max_right[i + 1] + nums[i + 1], 0)
        
        # Initialize the maximum sum as 0
        max_sum = 0

        # Iterate over each element in the array
        for i in range(n):
            # Calculate the maximum sum by combining the best left and right subarrays found for each element
            max_sum = max(max_sum, max_left[i] + nums[i] ** 2 + max_right[i])
        
        return max_sum