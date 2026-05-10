class Solution:
    def maximumJumps(self, nums: List[int], target: int) -> int:
        @lru_cache(maxsize = None)
        def dp(i: int) -> int:
            if i == n - 1:
                return 0

            max_jump = float('-inf')
            for j in range(i + 1, n):
                if abs(nums[j] - nums[i]) <= target:
                    max_jump = max(max_jump, 1 + dp(j))

            return max_jump
        
        n = len(nums)
        ans = dp(0)
        return -1 if ans < 0 else ans