class Solution:
    def longestNiceSubarray(self, nums: List[int]) -> int:
        # used_bits := Tracks bits used in current window
        # left := Start position of current window
        used_bits, left = 0, 0
        ans, n = 0, len(nums)   # Length of longest nice subarray found

        for right in range(n):
            # If the current number shares bits with window, shrink window from left
            # until there's no bit conflict
            while used_bits & nums[right] != 0:
                used_bits ^= nums[left] # Remove leftmost element's bits
                left += 1   # Shrink window from left
            
            # Add current number to the window
            used_bits ^= nums[right]

            # Update max length if current window is longer
            ans = max(ans, right - left + 1)

        return ans