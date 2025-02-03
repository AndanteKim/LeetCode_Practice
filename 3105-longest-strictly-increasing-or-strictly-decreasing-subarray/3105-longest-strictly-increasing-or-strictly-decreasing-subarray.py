class Solution:
    def longestMonotonicSubarray(self, nums: List[int]) -> int:
        n, ans = len(nums), 0
        increasing, decreasing = float('-inf'), float('inf')
        inc_count, dec_count = 0, 0

        for i in range(n):
            if increasing < nums[i]:
                inc_count += 1
            else:
                inc_count = 1
            increasing = nums[i]

            if decreasing > nums[i]:
                dec_count += 1
            else:
                dec_count = 1
            decreasing = nums[i]

            ans = max(ans, inc_count, dec_count)

        return ans