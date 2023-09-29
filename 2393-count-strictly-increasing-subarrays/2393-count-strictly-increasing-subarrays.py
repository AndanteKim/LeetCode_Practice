class Solution:
    def countSubarrays(self, nums: List[int]) -> int:
        @lru_cache(maxsize = None)
        def dp(i: int) -> int:
            # base case
            if i == n - 1:
                return 1
            
            ways = 1
            if nums[i] < nums[i + 1]:
                ways += dp(i + 1)
            
            return ways
        
        n = len(nums)
        return sum(dp(i) for i in range(n))