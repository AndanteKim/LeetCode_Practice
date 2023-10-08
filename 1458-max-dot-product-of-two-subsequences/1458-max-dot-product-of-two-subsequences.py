class Solution:
    def maxDotProduct(self, nums1: List[int], nums2: List[int]) -> int:
        max1, max2 = max(nums1), max(nums2)
        min1, min2 = min(nums1), min(nums2)
        
        if min1 > 0 and max2 < 0:
            return min1 * max2
        
        if max1 < 0 and min2 > 0:
            return max1 * min2
        
        m, n = len(nums1), len(nums2)
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                use = nums1[i] * nums2[j] + dp[i + 1][j + 1]
                dp[i][j] = max(use, dp[i + 1][j] , dp[i][j + 1])
        return dp[0][0]