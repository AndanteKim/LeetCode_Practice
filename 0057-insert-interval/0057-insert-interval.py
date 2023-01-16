class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        insertI = bisect_left(intervals, newInterval)
        intervals.insert(insertI, newInterval)
        
        i = 0
        
        while i < len(intervals):
            s, e = intervals[i]
            if i > 0 and intervals[i-1][1] >= s:
                lastS, lastE = intervals[i-1]
                intervals[i-1:i+1] = [[lastS, max(lastE, e)]]
            else:
                i += 1
        return intervals