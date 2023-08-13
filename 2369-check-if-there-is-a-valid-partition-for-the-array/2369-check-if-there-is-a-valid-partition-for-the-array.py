class Solution:
    def dp(self, i: int, memo: Dict[int, int], nums: List[int]) -> bool:
        if i in memo:
            return memo[i]
        ans = False
        
        if i > 0 and nums[i] == nums[i - 1]:
            ans |= self.dp(i - 2, memo, nums)
        if i > 1 and nums[i] == nums[i - 1] == nums[i - 2]:
            ans |= self.dp(i - 3, memo, nums)
        if i > 1 and nums[i] == nums[i - 1] + 1 == nums[i - 2] + 2:
            ans |= self.dp(i - 3, memo, nums)
        memo[i] = ans
        return ans
    
    def validPartition(self, nums: List[int]) -> bool:
        n, memo = len(nums), {-1: True}
        return self.dp(n - 1, memo, nums)