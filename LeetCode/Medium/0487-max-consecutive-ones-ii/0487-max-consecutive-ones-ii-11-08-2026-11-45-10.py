class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        ans, curr, count = 0, 0, 0
        left, n = 0, len(nums)

        for right in range(n):
            if nums[right] == 0:
                count += 1
            
            while left < right and count >= 2:
                if nums[left] == 0:
                    count -= 1
                left += 1
            
            ans = max(ans, right - left + 1)

        return ans