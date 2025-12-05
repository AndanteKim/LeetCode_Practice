class Solution:
    def countPartitions(self, nums: List[int]) -> int:
        n, left, right = len(nums), 0, sum(nums)
        ans = 0

        for i in range(0, n - 1):
            left += nums[i]
            right -= nums[i]

            if abs(left - right) % 2 == 0:
                ans += 1

        return ans