class Solution:
    def gcdSum(self, nums: list[int]) -> int:
        def gcd(a: int, b: int) -> int:
            while b != 0:
                a, b = b, a % b

            return a 

        mx, n = 0, len(nums)
        prefix_gcd = [0] * n

        for i, num in enumerate(nums):
            mx = max(mx, num)
            prefix_gcd[i] = gcd(mx, num)

        prefix_gcd.sort()
        ans = 0
        for i in range((n >> 1)):
            ans += gcd(prefix_gcd[i], prefix_gcd[n - 1 - i])
        
        return ans