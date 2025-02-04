class Solution:
    def maxAscendingSum(self, nums: List[int]) -> int:
        max_sum, curr_subarr_sum = 0, nums[0]

        # Loop through the list starting from the second element
        for curr_idx in range(1, len(nums)):
            if nums[curr_idx] <= nums[curr_idx - 1]:
                # If the current element isn't greater than the previous one
                # update max_sum
                max_sum = max(max_sum, curr_subarr_sum)
                # Reset the sum for for the next ascending subarray
                curr_subarr_sum = 0
            curr_subarr_sum += nums[curr_idx]

        # Final check after the loop ends to account for the last ascending
        # subarray
        return max(max_sum, curr_subarr_sum)