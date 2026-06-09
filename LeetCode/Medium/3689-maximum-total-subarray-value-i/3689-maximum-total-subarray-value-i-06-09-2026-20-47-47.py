class Solution:
    def maxTotalValue(self, nums: List[int], k: int) -> int:
        mx, mn = float('-inf'), float('inf')

        for num in nums:
            mn = min(mn, num)
            mx = max(mx, num)

        return (mx - mn) * k