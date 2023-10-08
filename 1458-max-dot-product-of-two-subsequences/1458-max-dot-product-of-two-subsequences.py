class Solution:
    def maxDotProduct(self, nums1: List[int], nums2: List[int]) -> int:
        max1, max2 = max(nums1), max(nums2)
        min1, min2 = min(nums1), min(nums2)
        
        if max1 < 0 and min2 > 0:
            return max1 * min2
        if min1 > 0 and max2 < 0:
            return min1 * max2
        
        m = len(nums2) + 1
        dp, prev_dp = [0] * m, [0] * m
        for i in range(len(nums1) - 1, -1, -1):
            dp = [0] * m
            for j in range(len(nums2) - 1, -1, -1):
                use = nums1[i] * nums2[j] + prev_dp[j + 1]
                dp[j] = max(use, prev_dp[j], dp[j + 1])
            prev_dp = dp
        
        return dp[0]