class Solution:
    def countSubarrays(self, nums: List[int]) -> int:
        # sliding window
        left = prev = ans = 0
        for right in range(len(nums)):
            if prev >= nums[right]:
                left = right
            ans += right - left + 1
            prev = nums[right]
        
        return ans
        