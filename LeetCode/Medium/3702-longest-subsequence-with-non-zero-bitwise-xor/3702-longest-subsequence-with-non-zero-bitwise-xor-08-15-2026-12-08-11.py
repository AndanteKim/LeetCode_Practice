class Solution:
    def longestSubsequence(self, nums: List[int]) -> int:
        curr, n = 0, len(nums)
        all_zero = True

        for x in nums:
            curr ^= x
            if x > 0:
                all_zero = False

        if curr > 0:
            return n

        return n - 1 if all_zero == False else 0