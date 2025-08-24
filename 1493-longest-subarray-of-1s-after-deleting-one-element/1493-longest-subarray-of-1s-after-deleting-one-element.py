class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        # Number of zero's in the window. 
        zero_cnt, ans = 0, 0
        left, n = 0, len(nums)

        for right in range(n):
            zero_cnt += (nums[right] == 0)
            
            # Shrink the window until the count of zero's
            # is less than or equal to 1.
            while zero_cnt > 1:
                zero_cnt -= (nums[left] == 0)
                left += 1
            
            ans = max(ans, right - left)
        
        return ans