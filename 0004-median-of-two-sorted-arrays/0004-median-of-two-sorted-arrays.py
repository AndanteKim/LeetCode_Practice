class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        i, j, m, n = 0, 0, len(nums1), len(nums2)
        arr = []
        
        while i < m and j < n:
            if nums1[i] <= nums2[j]:
                arr.append(nums1[i])
                i += 1
            else:
                arr.append(nums2[j])
                j += 1
                
        if i < m:
            arr += nums1[i:]
        elif j < n:
            arr += nums2[j:]
            
        return arr[(m + n) // 2] if (m + n) % 2 else 0.5 * (arr[(m + n) // 2 - 1] + arr[(m + n) // 2])