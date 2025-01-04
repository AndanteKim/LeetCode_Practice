class Solution:
    def waysToSplitArray(self, nums: List[int]) -> int:
        n = len(nums)
        prefix, suffix = [0] * n, [0] * n
        prefix[0], suffix[0] = nums[0], nums[-1]

        for i in range(1, n):
            prefix[i] = prefix[i - 1] + nums[i]
            suffix[i] = suffix[i - 1] + nums[n - 1 - i]

        ans = 0
        for i in range(n - 1):
            if prefix[i] >= suffix[n - 2 - i]:
                ans += 1

        return ans
            
