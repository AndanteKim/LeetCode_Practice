class Solution:
    def minKBitFlips(self, nums: List[int], k: int) -> int:
        # Keeps track of flipped states
        flipped = [False] * len(nums)
        
        # Tracks valid flips within the past window
        valid_flips_from_past_window = 0
        
        # Counts total flips needed
        flip_count = 0
        
        for i in range(len(nums)):
            if i >= k:
                # Decrease count of valid flips from the past window if needed
                if flipped[i - k]:
                    valid_flips_from_past_window -= 1
                    
            # Check if current bit needs to be flipped
            if valid_flips_from_past_window % 2 == nums[i]:
                # If flipping the window extends beyond the array length.
                # return -1
                if i + k > len(nums):
                    return -1
                
                # Increment the count of valid flips and
                # mark current as flipped
                valid_flips_from_past_window += 1
                flipped[i] = True
                flip_count += 1
                
        return flip_count