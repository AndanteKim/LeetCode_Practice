class Solution:
    def leftRightDifference(self, nums: List[int]) -> List[int]:
        n = len(nums)
        left, right = [0] * (n + 1), [0] * (n + 1)

        for i in range(n):
            left[i + 1] = left[i] + nums[i]
            right[n - 1 - i] = right[n - i] + nums[n - 1 - i]

        ans = [0] * n
        for i in range(n):
            ans[i] = abs(left[i] - right[i + 1]) 

        return ans