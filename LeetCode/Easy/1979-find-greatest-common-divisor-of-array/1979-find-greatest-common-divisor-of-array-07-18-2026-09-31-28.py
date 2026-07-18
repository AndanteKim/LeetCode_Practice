class Solution:
    def findGCD(self, nums: List[int]) -> int:
        mx, mn = float('-inf'), float('inf')
        for num in nums:
            mn = min(mn, num)
            mx = max(mx, num)

        return math.gcd(mx, mn)