class Solution:
    def rob(self, nums: List[int]) -> int:
        @lru_cache(maxsize = None)
        def dp(i: int) -> int:
            if i >= n:
                return 0
            
            return max(nums[i] + dp(i + 2), dp(i + 1))
            
        
        n = len(nums)
        return dp(0)
        