class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        if len(nums) == 2:
            return max(nums[0], nums[1])
        return max(self.robSimple(nums, 0, len(nums) - 1), self.robSimple(nums, 1, len(nums)))
    
    def robSimple(self, nums: List[int], start: int, end: int) -> int:
        dp = [0] * (end - start)
        
        dp[0] = nums[start]
        dp[1] = max(dp[0], nums[start + 1])
        for i in range(start + 2, end):
            dp[i - start] = max(nums[i] + dp[i - start - 2], dp[i - start - 1])
        return dp[-1]