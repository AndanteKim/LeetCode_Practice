class Solution:
    def xorAfterQueries(self, nums: List[int], queries: List[List[int]]) -> int:
        MOD, n = 1_000_000_007, len(nums)

        for l, r, k, v in queries:
            idx = l
            while idx <= r:
                nums[idx] = (nums[idx] * v) % MOD

                idx += k

        ans = 0

        for num in nums:
            ans ^= num

        return ans