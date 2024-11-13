class Solution:
    def countFairPairs(self, nums: List[int], lower: int, upper: int) -> int:
        nums.sort()
        ans = 0
        for i in range(len(nums)):
            # Assume we have picked nums[i] as the first pair element.
            
            # 'low' indicates the number of possible pairs with sum < lower.
            low = bisect_left(nums, lower - nums[i], i + 1, len(nums))
            
            # 'high' indicates the number of possible pairs with sum <= upper.
            high = bisect_left(nums, upper - nums[i] + 1, i + 1, len(nums))
            
            # Their difference gives the number of elements with sum in the given range.
            ans += high - low
            
        return ans