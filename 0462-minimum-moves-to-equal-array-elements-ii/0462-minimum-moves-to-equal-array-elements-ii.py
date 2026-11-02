class Solution:
    def minMoves2(self, nums: list[int]) -> int:
        ans, l, r = 0, 0, len(nums) - 1
        nums.sort()

        while l < r:
            ans += nums[r] - nums[l]
            r -= 1
            l += 1

        return ans