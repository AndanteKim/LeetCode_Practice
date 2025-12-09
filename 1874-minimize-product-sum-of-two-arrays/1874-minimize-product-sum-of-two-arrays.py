class Solution:
    def minProductSum(self, nums1: List[int], nums2: List[int]) -> int:
        nums1.sort(reverse = True)
        nums2.sort()

        ans, n = 0, len(nums1)
        for i in range(n):
            ans += nums1[i] * nums2[i]
        
        return ans