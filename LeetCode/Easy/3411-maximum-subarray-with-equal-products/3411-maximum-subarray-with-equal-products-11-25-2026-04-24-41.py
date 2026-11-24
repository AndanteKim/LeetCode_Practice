class Solution:
    def maxLength(self, nums: List[int]) -> int:
        ans, n = 0, len(nums)

        for i in range(n - 1):
            for j in range(i, n - 1):
                curr, curr_lcm, curr_gcd = nums[j], nums[j], nums[j]
                for k in range(j + 1, n):
                    curr *= nums[k]
                    curr_lcm, curr_gcd = lcm(curr_lcm, nums[k]), gcd(curr_gcd, nums[k])
                    if curr == curr_lcm * curr_gcd:
                        ans = max(ans, k - j + 1)

        return ans