class Solution:
    def minTaps(self, n: int, ranges: List[int]) -> int:
        dp = [n + 1] * (n + 1)
        dp[0] = 0
    
        for start_line in range(len(ranges)):
            for i in range(max(start_line - ranges[start_line] + 1, 0), min(start_line + ranges[start_line], n) + 1):
                dp[i] = min(dp[i], dp[max(0, start_line - ranges[start_line])] + 1)
        
        return -1 if dp[-1] == n + 1 else dp[-1]