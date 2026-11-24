class Solution:
    def maxLength(self, nums: List[int]) -> int:
        ans, prod = 2, 1
        n = len(nums)
        start, end = 0, 0

        while end < n:
            while gcd(prod, nums[end]) > 1:
                prod //= nums[start]
                start += 1
            prod *= nums[end]
            ans = max(ans, end - start + 1)
            end += 1
        
        return ans