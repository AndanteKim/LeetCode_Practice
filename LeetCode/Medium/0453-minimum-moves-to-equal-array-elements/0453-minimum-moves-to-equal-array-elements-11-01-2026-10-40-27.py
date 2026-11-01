class Solution:
    def minMoves(self, nums: list[int]) -> int:
        ans, mn = 0, min(nums)
        
        for num in nums:
            ans += num - mn

        return ans