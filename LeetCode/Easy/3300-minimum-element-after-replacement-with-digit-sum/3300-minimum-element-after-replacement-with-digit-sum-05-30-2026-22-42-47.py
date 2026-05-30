class Solution:
    def minElement(self, nums: List[int]) -> int:
        ans = float('inf')

        for num in nums:
            curr_sum = 0
            while num > 0:
                curr_sum += num % 10
                num //= 10
            ans = min(ans, curr_sum)

        return ans