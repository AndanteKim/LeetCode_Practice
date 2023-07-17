class Solution:
    def maxUncrossedLines(self, nums1: List[int], nums2: List[int]) -> int:
        
        @lru_cache(maxsize = None)
        def dp(i: int, j: int) -> int:
            if i >= len(nums1) or j >= len(nums2):
                return 0
            
            ans = 0
            if nums1[i] == nums2[j]:
                ans += max(1 + dp(i + 1, j + 1), dp(i, j + 1), dp(i + 1, j))
            else:
                ans += max(dp(i, j + 1), dp(i + 1, j))
            
            return ans
        
        return dp(0, 0)