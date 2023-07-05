class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        all_ones, one_zero, ans = 0, 0, 0
        
        for num in nums:
            if num == 1:
                all_ones += 1
                one_zero += 1
            else:
                one_zero = all_ones
                all_ones = 0
            
            ans = max(ans, all_ones, one_zero)
        
        return n - 1 if all_ones == n else ans
                