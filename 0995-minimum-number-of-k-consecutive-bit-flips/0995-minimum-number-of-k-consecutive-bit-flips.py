class Solution:
    def minKBitFlips(self, nums: List[int], k: int) -> int:
        # Track the current number of flips
        curr_flips = 0
        # Track the total nuumber of flips
        total_flips = 0
        
        for i in range(len(nums)):
            # If the window slides out of the range and the leftmost element is
            # marked as flipped (2), decrement curr_flips
            if i >= k and nums[i - k] == 2:
                curr_flips -= 1
            
            # Check if the current bit needs to be flipped
            if curr_flips % 2 == nums[i]:
                # If flipping would exceed array bounds, return -1
                if i + k > len(nums):
                    return -1
                
                # Mark the current bit as flipped
                nums[i] = 2
                curr_flips += 1
                total_flips += 1
                
        return total_flips