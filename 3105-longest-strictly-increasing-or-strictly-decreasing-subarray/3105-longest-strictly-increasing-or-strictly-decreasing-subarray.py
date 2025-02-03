class Solution:
    def longestMonotonicSubarray(self, nums: List[int]) -> int:
        # Track current lengths of increasing and decreasing sequences
        inc_len, dec_len, max_len = 1, 1, 1

        # Iterate through array comparing adjacent elements
        for pos in range(len(nums) - 1):
            if nums[pos + 1] > nums[pos]:
                # If the next element is larger, extend increasing sequence
                inc_len += 1
                dec_len = 1     # Reset decreasing sequence
            elif nums[pos + 1] < nums[pos]:
                # If the next element is smaller, extend decreasing sequence
                inc_len = 1     # Reset increasing sequence
                dec_len += 1
            else:
                # If elements are equal, reset both sequences
                inc_len = dec_len = 1

            # Updapte max length considering both sequences
            max_len = max(max_len, inc_len, dec_len)

        return max_len

