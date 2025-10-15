class Solution:
    def maxIncreasingSubarrays(self, nums: List[int]) -> int:
        n, precnt, cnt, ans = len(nums), 0, 1, 0

        for i in range(n - 1):
            if nums[i] < nums[i + 1]:
                cnt += 1
            else:
                precnt, cnt = cnt, 1

            ans = max(ans, min(cnt, precnt))
            ans = max(ans, cnt >> 1)

        return ans