class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        ans = []
        
        nums1.sort()
        nums2.sort()
        
        i, j = 0, 0
        
        while i < len(nums1):
            idx = bisect_left(nums2, nums1[i])
            cnt2 = 0
            
            while idx < len(nums2) and nums2[idx] == nums1[i]:
                cnt2 += 1
                idx += 1
            
            cnt1 = 0
            while j < len(nums1) and nums1[j] == nums1[i]:
                j += 1
                cnt1 += 1
                
            ans.extend([nums1[i]] * min(cnt1, cnt2))
            i = j
            
        return ans
        