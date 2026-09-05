class Solution:
    def firstStableIndex(self, nums: list[int], k: int) -> int:
        n = len(nums)
        prefix, suffix = [0] * (n + 1), [float('inf')] * (n + 1)

        for i in range(n):
            prefix[i + 1] = max(prefix[i], nums[i])
            suffix[n - 1 - i] = min(suffix[n - i], nums[n - 1 - i])

        for i in range(n):
            if prefix[i + 1] - suffix[i] <= k:
                return i

        return -1