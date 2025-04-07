class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        # Find sum of array elements
        total = sum(nums)

        # If total_sum is odd, it cannot be partitioned into equal sum subsets
        if total % 2 != 0:
            return False
        
        # Construct a dp talbe of size (subset_sum + 1)
        n, subset_sum = len(nums), total >> 1
        dp = [False] * (subset_sum + 1)
        dp[0] = True

        for num in nums:
            for j in range(subset_sum, num - 1, -1):
                dp[j] = dp[j] or dp[j - num]

        return dp[subset_sum]