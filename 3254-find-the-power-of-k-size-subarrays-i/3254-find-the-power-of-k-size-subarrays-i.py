class Solution:
    def resultsArray(self, nums: List[int], k: int) -> List[int]:
        if k == 1:
            return nums     # If k is 1, every single element is a valid subarray
        
        length = len(nums)
        ans, consecutive_count = [-1] * (length - k + 1), 1     # Count of consecutive elements
        
        for i in range(length - 1):
            if nums[i] + 1 == nums[i + 1]:
                consecutive_count += 1
            else:
                consecutive_count = 1       # Reset count if not consecutive
                
            # If we've enough consecutive elements, update the result
            if consecutive_count >= k:
                ans[i - k + 2] = nums[i + 1]
        
        
        return ans
        
        