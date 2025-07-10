class Solution:
    def maxFreeTime(self, eventTime: int, startTime: List[int], endTime: List[int]) -> int:
        ans, n = 0, len(startTime)
        q, t1, t2 = [False] * n, 0, 0
        for i in range(n):
            if endTime[i] - startTime[i] <= t1:
                q[i] = True
            t1 = max(t1, startTime[i] - (0 if i == 0 else endTime[i - 1]))
            
            if endTime[n - i - 1] - startTime[n - i - 1] <= t2:
                q[n - i - 1] = True
            t2 = max(t2, (eventTime if i == 0 else startTime[n - i]) - endTime[n - i - 1])

        for i in range(n):
            right = eventTime if i == n - 1 else startTime[i + 1]
            left = 0 if i == 0 else endTime[i - 1]
            if q[i]:
                ans = max(ans, right - left)
            else:
                ans = max(ans, right - left - (endTime[i] - startTime[i]))

        return ans