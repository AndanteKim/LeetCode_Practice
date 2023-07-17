class Solution:
    def maxUncrossedLines(self, nums1: List[int], nums2: List[int]) -> int:
        n1, n2 = len(nums1), len(nums2)
        dp, prev = [0] * (n2 + 1), [0] * (n2 + 1)
        
        for i in range(1, n1 + 1):
            for j in range(1, n2 + 1):
                if nums1[i - 1] == nums2[j - 1]:
                    dp[j] = 1 + prev[j - 1]
                else:
                    dp[j] = max(dp[j - 1], prev[j])
            prev = dp[:]
            
        return dp[-1]