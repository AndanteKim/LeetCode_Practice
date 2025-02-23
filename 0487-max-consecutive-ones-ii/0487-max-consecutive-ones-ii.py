class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        ans, left, used = 0, 0, False

        for right in range(len(nums)):
            if nums[right] == 0:
                if not used:
                    used = True
                else:
                    while left < right and nums[left] != 0:
                        left += 1
                    left += 1

            ans = max(ans, right - left + 1)

        return ans