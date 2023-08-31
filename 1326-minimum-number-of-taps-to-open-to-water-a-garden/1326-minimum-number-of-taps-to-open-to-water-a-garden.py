class Solution:
    def minTaps(self, n: int, ranges: List[int]) -> int:
        # define an inf value as dp array
        dp = [float('inf')] * (n + 1)
        
        # Initialize the starting position of the garden
        dp[0] = 0
        
        for i in range(n + 1):
            # calculate the leftmost position reachable by the current tap
            tap_start = max(0, i - ranges[i])
            # calculate the rightmost position reachable by the current tap
            tap_end = min(n, i + ranges[i])
            
            for j in range(tap_start, tap_end + 1):
                # update with the minimum number of taps
                dp[tap_end] = min(dp[tap_end], dp[j] + 1)
                
        # check if the garden can be watered completely
        return -1 if dp[n] == float('inf') else dp[n]
        