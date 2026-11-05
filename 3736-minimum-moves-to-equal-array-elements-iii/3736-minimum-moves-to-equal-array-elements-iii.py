class Solution:
    def minMoves(self, nums: List[int]) -> int:
        ans, mx = 0, max(nums)

        for num in nums:
            ans += abs(mx - num)

        return ans