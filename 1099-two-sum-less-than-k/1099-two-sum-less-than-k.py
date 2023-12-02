class Solution:
    def twoSumLessThanK(self, nums: List[int], k: int) -> int:
        nums.sort()
        
        ans, left, right = -1, 0, len(nums) - 1
        
        while left < right:
            if nums[left] + nums[right] < k:
                ans = max(ans, nums[left] + nums[right])
                left += 1
            else:
                right -= 1
        
        return ans