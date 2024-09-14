class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        # Longest consecutive sequence of the maximum value
        # k := maximum number
        k = ans = curr_streak = 0
        
        for num in nums:
            if k < num:
                k = num
                ans, curr_streak = 0, 0
            
            if k == num:
                curr_streak += 1
            else:
                curr_streak = 0
                
            ans = max(ans, curr_streak)
            
        return ans