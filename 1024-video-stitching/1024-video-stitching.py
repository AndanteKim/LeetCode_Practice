class Solution:
    def videoStitching(self, clips: List[List[int]], time: int) -> int:
        dp = [time + 1] * (time + 1)
        dp[0] = 0
        
        for i in range(1, time + 1):
            if dp[i - 1] >= time:
                continue
            for start, end in clips:
                if start <= i <= end:
                    dp[i] = min(dp[i], dp[start] + 1)
                    
        return -1 if dp[time] == time + 1 else dp[time] 