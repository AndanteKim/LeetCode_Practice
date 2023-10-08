class Solution:
    def maxDotProduct(self, nums1: List[int], nums2: List[int]) -> int:
        @lru_cache(maxsize = None)
        def dp(i: int, j: int) -> int:
            if i == n1 or j == n2:
                return 0
            
            return max(dp(i + 1, j), dp(i, j + 1), nums1[i] * nums2[j] + dp(i + 1, j + 1))
        
        n1, n2 = len(nums1), len(nums2)
        max1, min1 = max(nums1), min(nums1)
        max2, min2 = max(nums2), min(nums2)
        if max1 < 0 and min2 > 0:
            return max1 * min2
        if min1 > 0 and max2 < 0:
            return min1 * max(nums2)
        
        return dp(0, 0)