class Solution:
    def maxDistance(self, nums1: List[int], nums2: List[int]) -> int:
        m, n, ans = len(nums1), len(nums2), 0
        nums2.reverse()
        
        for i in range(m):
            left, right = 0, n
            
            while left < right:
                mid = (left + right) // 2
                if nums1[i] <= nums2[mid]:
                    right = mid
                else:
                    left = mid + 1
            ans = max(ans, n - left - i - 1)
        
                
        return ans