class Solution:
    def maxAlternatingSum(self, nums: List[int]) -> int:
        ans, n = 0, len(nums)
        abs_nums = [abs(num) for num in nums]
        abs_nums.sort()
        j = n - 1
        
        for i in range(n >> 1):
            ans -= abs_nums[i] ** 2
            ans += abs_nums[j] ** 2
            j -= 1
        
        if n % 2:
            ans += abs_nums[j] ** 2

        return ans