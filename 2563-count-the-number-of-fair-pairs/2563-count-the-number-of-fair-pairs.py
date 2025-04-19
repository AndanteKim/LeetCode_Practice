class Solution:
    def countFairPairs(self, nums: List[int], lower: int, upper: int) -> int:
        nums.sort()
        ans, n = 0, len(nums)

        for i in range(n):
            left = bisect_left(nums, lower - nums[i], i + 1)
            right = bisect_right(nums, upper - nums[i], i + 1)
            ans += right - left
        
        return ans