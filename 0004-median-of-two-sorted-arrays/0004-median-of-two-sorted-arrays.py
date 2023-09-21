class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        i, j, m, n = 0, 0, len(nums1), len(nums2)
        
        # Get the smaller value between nums1[p1] and nums2[p2]
        def get_min():
            nonlocal i, j
            if i < m and j < n:
                if nums1[i] < nums2[j]:
                    ans = nums1[i]
                    i += 1
                else:
                    ans = nums2[j]
                    j += 1
            elif j == n:
                ans = nums1[i]
                i += 1
            else:
                ans = nums2[j]
                j += 1
            return ans
        
        
        if (m + n) % 2 == 0:
            for _ in range((m + n) // 2 - 1):
                _ = get_min()
            
            return (get_min() + get_min()) / 2
        
        else:
            for _ in range((m + n) // 2):
                _ = get_min()
            return get_min()