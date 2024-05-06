class Solution:
    def countPairs(self, nums1: List[int], nums2: List[int]) -> int:
        n = len(nums1)
        
        # Diff[i] stores nums1[i] - nums2[i]
        diff = [nums1[i] - nums2[i] for i in range(n)]
        diff.sort()
        
        # Count the number of valid pairs
        ans, left, right = 0, 0, n - 1
        
        while left < right:
            # Left makes a valid pair with right
            # Right also makes a valid pair with indices between the pointers
            if diff[left] + diff[right] > 0:
                ans += right - left
                right -= 1
            # Left and right are not a valid pair
            else:
                left += 1
        
        return ans
         