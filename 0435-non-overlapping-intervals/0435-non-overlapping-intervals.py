class Solution:
    def dfs(self, i: int, intervals: List[List[int]], dp: List[int]) -> int:
        if i == self.n:
            return 0
        
        if dp[i] != -1:
            return dp[i]
        
        not_take = 0 + self.dfs(i + 1, intervals, dp)
        start, end = intervals[i]
        
        temp = [end, end]
        idx = bisect.bisect_left(intervals, temp, i + 1, self.n)
        
        take = 1 + self.dfs(idx, intervals, dp)
        dp[i] = max(take, not_take)
        return max(take, not_take)
    
    
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        self.n = len(intervals)
        intervals.sort()
        dp = [-1] * self.n
        
        return self.n - self.dfs(0, intervals, dp);