class Solution:
    def longestSubsequence(self, arr: List[int], difference: int) -> int:
        n, ans = len(arr), 1
        dp = dict()
        
        for num in arr:
            dp[num] = dp.get(num - difference, 0) + 1
            ans = max(dp[num], ans)
        
        return ans
        