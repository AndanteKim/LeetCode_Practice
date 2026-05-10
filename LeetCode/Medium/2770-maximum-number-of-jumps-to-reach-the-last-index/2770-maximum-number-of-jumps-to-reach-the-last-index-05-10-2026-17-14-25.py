class Solution:
    def maximumJumps(self, nums: List[int], target: int) -> int:
        @lru_cache(maxsize = None)
        def dp(i: int) -> int:
            if i == n - 1:
                return 0

            max_jump = -1
            for j in range(i + 1, n):
                if abs(nums[j] - nums[i]) <= target:
                    next_step = dp(j)
                    if next_step != -1:
                        max_jump = max(max_jump, 1 + next_step)

            return max_jump
        
        n = len(nums)
        return dp(0)