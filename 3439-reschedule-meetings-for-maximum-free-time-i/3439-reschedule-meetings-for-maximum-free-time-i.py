class Solution:
    def maxFreeTime(self, eventTime: int, k: int, startTime: List[int], endTime: List[int]) -> int:
        n, ans, t = len(startTime), 0, 0

        for i in range(n):
            t += endTime[i] - startTime[i]
            left = 0 if i == k - 1 else endTime[i - k]
            right = eventTime if i == n - 1 else startTime[i + 1]
            ans = max(ans, right - left - t)
            if i >= k - 1:
                t -= endTime[i - k + 1] - startTime[i - k + 1]
        
        return ans
