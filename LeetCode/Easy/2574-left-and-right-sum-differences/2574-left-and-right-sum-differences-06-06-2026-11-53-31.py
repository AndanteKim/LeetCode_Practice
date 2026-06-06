class Solution:
    def leftRightDifference(self, nums: List[int]) -> List[int]:
        n, left = len(nums), 0
        ans = [0] * n

        for i in range(n):
            ans[i] = left
            left += nums[i]

        right = 0
        for i in range(n - 1, -1, -1):
            ans[i] = abs(ans[i] - right)
            right += nums[i]

        return ans