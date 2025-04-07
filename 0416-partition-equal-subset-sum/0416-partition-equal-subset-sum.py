class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        @lru_cache(maxsize = None)
        def dp(i: int, subset_sum: int) -> bool:
            # Base cases
            if subset_sum == 0:
                return True
            
            if i == 0 or subset_sum < 0:
                return False
            
            ans = dp(i - 1, subset_sum - nums[i - 1]) or dp(i - 1, subset_sum)
            return ans

        # Find sum of array elements
        total = sum(nums)

        # If total sum is odd, it cannot be partitioned into equal sum subsets
        if total % 2 != 0:
            return False
        
        n, subset_sum = len(nums), total >> 1

        return dp(n - 1, subset_sum)