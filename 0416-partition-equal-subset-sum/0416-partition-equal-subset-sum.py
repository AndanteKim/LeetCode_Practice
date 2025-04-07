class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        def dp(i: int, subset_sum: int) -> bool:
            # Base cases
            if subset_sum == 0:
                return True
            
            if i == 0 or subset_sum < 0:
                return False

            if memo[i][subset_sum] != -1:
                return True if memo[i][subset_sum] else False
            
            memo[i][subset_sum] = dp(i - 1, subset_sum - nums[i - 1]) or dp(i - 1, subset_sum)
            return memo[i][subset_sum]

        # Find sum of array elements
        total = sum(nums)

        # If total sum is odd, it cannot be partitioned into equal sum subsets
        if total % 2 != 0:
            return False
        
        n, subset_sum = len(nums), total >> 1
        memo = [[-1] * (subset_sum + 1) for _ in range(n + 1)]

        return dp(n - 1, subset_sum)