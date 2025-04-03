class Solution:
    def maximumTripletValue(self, nums: List[int]) -> int:
        ans, n = 0, len(nums)
        left_max, right_max = [0] * n, [0] * n

        for i in range(1, n):
            left_max[i] = max(left_max[i - 1], nums[i - 1])
            right_max[n - 1 - i] = max(right_max[n - i], nums[n - i])

        for j in range(1, n - 1):
            ans = max(ans, (left_max[j] - nums[j]) * right_max[j])

        return ans