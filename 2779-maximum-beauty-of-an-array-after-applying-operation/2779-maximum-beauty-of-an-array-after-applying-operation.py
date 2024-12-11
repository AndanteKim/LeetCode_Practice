class Solution:
    def maximumBeauty(self, nums: List[int], k: int) -> int:
        ans, n = 0, len(nums)
        nums.sort()
        left = 0
        
        for right in range(n):
            while left <= right and nums[right] - nums[left] > 2 * k:
                left += 1
            ans = max(ans, right - left + 1)
        
        return ans