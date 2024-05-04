class Solution:
    def countPairs(self, nums1: List[int], nums2: List[int]) -> int:
        n, ans = len(nums1), 0
        
        # diff[i] stores nums1[i] - nums2[i]
        diff = [nums1[i] - nums2[i] for i in range(n)]
        diff.sort()
        
        for i in range(n):
            # All indices j following i make a valid pair
            if diff[i] > 0:
                ans += n - i - 1
                
            # Binary search to find the first index j
            # that makes a valid pair with i
            else:
                left, right = i + 1, n - 1
                while left <= right:
                    mid = (left + right) >> 1
                    # If diff[mid] is a valid pair, search in left half
                    if diff[i] + diff[mid] > 0:
                        right = mid - 1
                    # If diff[mid] doesn't make a valid pair, search in right half
                    else:
                        left = mid + 1
            
            # After the search left points to the first index j that makes
            # a valid pair with i, so we count that and all following indices
                ans += n - left
                
        
        return ans