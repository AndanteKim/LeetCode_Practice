class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        m, n = len(nums1), len(nums2)
        if m > n:
            return self.findMedianSortedArrays(nums2, nums1)
        
        left, right = 0, m
        
        while left <= right:
            partA = (left + right) >> 1
            partB = ((m + n + 1) >> 1) - partA
            
            maxLeftA = float('-inf') if partA == 0 else nums1[partA - 1]
            minRightA = float('inf') if partA == m else nums1[partA]
            maxLeftB = float('-inf') if partB == 0 else nums2[partB - 1]
            minRightB = float('inf') if partB == n else nums2[partB]
            
            if maxLeftA <= minRightB and maxLeftB <= minRightA:
                if (m + n) % 2 == 0:
                    return (max(maxLeftA, maxLeftB) + min(minRightA, minRightB)) / 2
                else:
                    return max(maxLeftA, maxLeftB)
            elif maxLeftA > minRightB:
                right = partA - 1
            else:
                left = partA + 1
            