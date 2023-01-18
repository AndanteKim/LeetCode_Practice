class Solution:
    def findBestSubarray(self, nums: List[int], left: int, right: int) -> int:
        
        # base case: empty array
        if left > right:
            return -math.inf
        
        mid = (left + right) >> 1
        curr = best_left_sum = best_right_sum = 0
        
        for i in range(mid - 1, left - 1, -1):
            curr += nums[i]
            best_left_sum = max(best_left_sum, curr)
        
        #Reset curr and iterate from the middle to the end
        curr = 0
        for i in range(mid + 1, right + 1):
            curr += nums[i]
            best_right_sum = max(best_right_sum, curr)
            
        best_combined_sum = nums[mid] + best_left_sum + best_right_sum
        left_half = self.findBestSubarray(nums, left, mid - 1)
        right_half = self.findBestSubarray(nums, mid + 1, right)
        
        return max(best_combined_sum, left_half, right_half)
    
    def maxSubArray(self, nums: List[int]) -> int:
        
        return self.findBestSubarray(nums, 0, len(nums) - 1)