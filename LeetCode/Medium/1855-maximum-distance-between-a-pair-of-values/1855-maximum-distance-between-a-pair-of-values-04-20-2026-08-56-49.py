class Solution:
    def maxDistance(self, nums1: List[int], nums2: List[int]) -> int:
        ans, p1, p2 = 0, 0, 0
        
        while p1 < len(nums1) and p2 < len(nums2):
            if nums1[p1] > nums2[p2]:
                p1 += 1
            
            else:
                ans = max(ans, p2 - p1)
                p2 += 1
        return ans