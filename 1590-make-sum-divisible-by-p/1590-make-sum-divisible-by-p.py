class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:
        n, total_sum = len(nums), 0
        
        # Step 1: Calculate total sum and target remainder
        for num in nums:
            total_sum = (total_sum + num) % p
            
        target = total_sum % p
        # If the array is already divisible by p
        if target == 0:
            return 0
            
        # Step 2: Use a dict to track prefix sum mod p
        # To handle the case where the whole prefix is the answer
        mod_map, curr_sum, min_len = {0: -1}, 0, n
        
        # Step 3: Iterate over the array
        for i in range(n):
            curr_sum = (curr_sum + nums[i]) % p
            
            # Calculate what we need to remove
            needed = (curr_sum - target + p) % p
            
            # If we've seen the needed remainder, we can consider this subarray
            if needed in mod_map:
                min_len = min(min_len, i - mod_map[needed])
            
            # Store the current remainder and index
            mod_map[curr_sum] = i
            
        # Step 4: Return result
        return -1 if min_len == n else min_len