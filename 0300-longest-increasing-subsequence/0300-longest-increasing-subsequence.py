class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        @lru_cache(maxsize = None)
        def dp(i: int) -> int:
            ans = 1
            for j in range(i):
                if nums[i] > nums[j]:
                    ans = max(ans, dp(j) + 1)
            return ans
        
        return max(dp(i) for i in range(len(nums)))