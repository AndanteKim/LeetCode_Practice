class Solution:
    def countMaxOrSubsets(self, nums: List[int]) -> int:
        max_or_val, dp = 0, [0] * (1 << 17)
        
        # Initialize the empty subset
        dp[0] = 1
        
        # Iterate through each number in the input array
        for num in nums:
            for i in range(max_or_val, -1, -1):
                # For each existing subset, create a new subset by including the current number
                dp[i | num] += dp[i]
            
            # Update the maximum OR value
            max_or_val |= num

        return dp[max_or_val]