class Solution:
    def threeSumSmaller(self, nums: List[int], target: int) -> int:
        ans, n = 0, len(nums)
        nums.sort()
        for i in range(n - 2):
            for j in range(i + 1, n - 1):
                ans += max(0, bisect_left(nums, target - nums[i] - nums[j]) - j - 1)

        return ans