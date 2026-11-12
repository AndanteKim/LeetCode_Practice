class Solution:
    def longestMonotonicSubarray(self, nums: List[int]) -> int:
        inc = dec = mx = 1

        for i in range(len(nums) - 1):
            if nums[i] < nums[i + 1]:
                inc += 1
                dec = 1
            elif nums[i] > nums[i + 1]:
                dec += 1
                inc = 1
            else:
                inc = dec = 1
            mx = max(mx, inc, dec)

        return mx