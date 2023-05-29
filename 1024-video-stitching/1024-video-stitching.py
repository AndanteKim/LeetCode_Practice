class Solution:
    def videoStitching(self, clips: List[List[int]], time: int) -> int:
        clips.sort()
        dp = [101] * 101
        dp[0] = 0
        
        for start, end in clips:
            for i in range(start + 1, end + 1):
                dp[i] = min(dp[i], dp[start] + 1)
        
        return -1 if dp[time] >= 100 else dp[time]