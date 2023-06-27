class Solution:
    def dp(self, i: int, nums: List[int], memo: Dict[int, int]) -> int:
        ans = 1
        if i in memo:
            return memo[i]
        
        for j in range(i):
            if nums[i] > nums[j]:
                ans = max(ans, self.dp(j, nums, memo) + 1)
                
        memo[i] = ans
        return ans
    
    def lengthOfLIS(self, nums: List[int]) -> int:
        memo = dict()
        return max(self.dp(i, nums, memo) for i in range(len(nums)))