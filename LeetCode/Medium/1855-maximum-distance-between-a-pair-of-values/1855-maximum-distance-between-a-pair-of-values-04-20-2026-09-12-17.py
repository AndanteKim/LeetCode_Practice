class Solution:
    def maxDistance(self, nums1: List[int], nums2: List[int]) -> int:
        ans, m, n, j = 0, len(nums1), len(nums2), 0
        for i in range(m):
            j = max(i, j)
            while j < n and nums1[i] <= nums2[j]:
                ans = max(ans, j - i)
                j += 1

        return ans