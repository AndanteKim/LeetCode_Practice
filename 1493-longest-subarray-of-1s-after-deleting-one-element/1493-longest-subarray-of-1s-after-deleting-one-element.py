class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        ans, zero_count, left = 0, 0, 0
        
        for right in range(len(nums)):
            zero_count += (nums[right] == 0)
            
            while zero_count > 1:
                zero_count -= (nums[left] == 0)
                left += 1
            
            ans = max(ans, right - left)
        return ans