class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:
        n, target = len(nums), sum(nums) % p
        
        # Base case
        if target == 0:
            return 0

        # To handle the case where the whole prefix is the answer
        # Track the prefix sum mod p
        mod_map = {0: -1}

        curr_sum, min_len = 0, n

        for i in range(n):
            curr_sum = (curr_sum + nums[i]) % p

            # Calculate what we need to remove
            needed = (curr_sum - target + p) % p

            # If we've seen the needed remainder, we can consider this subarray
            if needed in mod_map:
                min_len = min(min_len, i - mod_map[needed])
            
            # Store the current remainder and index
            mod_map[curr_sum] = i

        # Output the answer
        return -1 if min_len == n else min_len 