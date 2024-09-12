class Solution:
    def longestNiceSubarray(self, nums: List[int]) -> int:
        left, ans, used = 0, 0, 0
        
        for right in range(len(nums)):
            while left < right and (used & nums[right]):
                used ^= nums[left]
                left += 1
            used |= nums[right]
            ans = max(ans, right - left + 1)
            
        return ans