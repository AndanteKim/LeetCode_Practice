class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        @lru_cache(maxsize = None)
        def dp(i: int, curr: int) -> int:
            if i == n:
                return 1 if curr == target else 0

            curr = dp(i + 1, curr + nums[i]) + dp(i + 1, curr - nums[i])
            return curr

        n = len(nums)
        return dp(0, 0)