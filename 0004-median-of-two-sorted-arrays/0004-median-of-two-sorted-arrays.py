class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        n1, n2 = len(nums1), len(nums2)
        n = n1 + n2
        
        def solve(k: int, n1_start: int, n1_end: int, n2_start: int, n2_end: int) -> int:
            # If the segment of an array is empty, it means we have passed all its element
            #, just return the corresponding element in the other array
            if n1_start > n1_end:
                return nums2[k - n1_start]
            if n2_start > n2_end:
                return nums1[k - n2_start]
            
            # Get the middle indices and middle values of nums1, nums2
            n1_index, n2_index = (n1_start + n1_end) >> 1, (n2_start + n2_end) >> 1
            n1_val, n2_val = nums1[n1_index], nums2[n2_index]
            
            # If k is in the right half of nums1 + nums2, remove the larger right half.
            if n1_index + n2_index < k:
                if n1_val > n2_val:
                    return solve(k, n1_start, n1_end, n2_index + 1, n2_end)
                else:
                    return solve(k, n1_index + 1, n1_end, n2_start, n2_end)
            else:
                if n1_val > n2_val:
                    return solve(k, n1_start, n1_index - 1, n2_start, n2_end)
                else:
                    return solve(k, n1_start, n1_end, n2_start, n2_index - 1)
        
        if n % 2:
            return solve(n // 2, 0, n1 - 1, 0, n2 - 1)
        else:
            return (solve(n // 2 - 1, 0, n1 - 1, 0, n2 - 1) + solve(n // 2, 0, n1 - 1, 0, n2 - 1)) / 2