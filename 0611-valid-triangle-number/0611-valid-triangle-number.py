class Solution:
    def triangleNumber(self, nums: List[int]) -> int:
        nums.sort()
        ans, n = 0, len(nums)

        for i in range(n - 2):
            for j in range(i + 1, n - 1):
                ans += bisect_left(nums, nums[i] + nums[j], j + 1, n) - j - 1

        return ans