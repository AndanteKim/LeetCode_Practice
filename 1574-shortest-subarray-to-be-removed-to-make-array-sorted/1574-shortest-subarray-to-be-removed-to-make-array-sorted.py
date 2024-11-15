class Solution:
    def findLengthOfShortestSubarray(self, arr: List[int]) -> int:
        n = len(arr)
        left, right = 0, n - 1
        
        # Find the longest non-decreasing prefix
        while left + 1 < n and arr[left] <= arr[left + 1]:
            left += 1
            
        # If the entire array is sorted
        if left == n - 1:
            return 0
        
        # Find the longest non-decreasing suffix
        while right > 0 and arr[right - 1] <= arr[right]:
            right -= 1
            
        # Initial assumption: Remove everything between the prefix and suffix
        min_length = min(n - left - 1, right)
        
        # Use binary search to merge prefix and suffix
        for i in range(left + 1):
            j = bisect_left(arr, arr[i], right, n)
            min_length = min(min_length, j - i - 1)
        
        return min_length