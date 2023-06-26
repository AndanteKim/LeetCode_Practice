class Solution:
    def robFrom(self, i: int, nums: List[int], memo: Dict[int, int]) -> int:
        if i >= len(nums):
            return 0
        
        if i in memo:
            return memo[i]
        
        ans = max(self.robFrom(i + 1, nums, memo), self.robFrom(i + 2, nums, memo) + nums[i])
        memo[i] = ans
        return ans
    
    def rob(self, nums: List[int]) -> int:
        memo = dict()
        return self.robFrom(0, nums, memo)