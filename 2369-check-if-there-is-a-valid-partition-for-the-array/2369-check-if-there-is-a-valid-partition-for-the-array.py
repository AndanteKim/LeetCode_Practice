class Solution:
    def validPartition(self, nums: List[int]) -> bool:
        n = len(nums)
        memo = {-1: True}
        
        def dp(i: int) -> bool:
            if i in memo:
                return memo[i]
            
            ans = False
            if i > 0 and nums[i] == nums[i - 1]:
                ans |= dp(i - 2)
            if i > 1 and nums[i] == nums[i - 1] == nums[i - 2]:
                ans |= dp(i - 3)
            if i > 1 and nums[i] == nums[i - 1] + 1 == nums[i - 2] + 2:
                ans |= dp(i - 3)
            memo[i] = ans
            return ans
            
            
        return dp(n - 1)
        