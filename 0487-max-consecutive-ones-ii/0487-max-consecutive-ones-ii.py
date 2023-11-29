class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        ans, flip, left = 0, False, 0
        for right in range(len(nums)):
            if nums[right] == 0:
                if not flip:
                    flip = True
                else:
                    while left < right and nums[left] != 0:
                        left += 1
                    left += 1
            
            ans = max(ans, right - left + 1)
            
            
        return ans