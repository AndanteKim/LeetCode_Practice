class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        insertI = bisect_left(intervals, newInterval)
        intervals.insert(insertI, newInterval)
        
        stack = []
        
        for s, e in intervals:
            if stack and stack[-1][1] >= s:
                lastS, lastE = stack.pop()
                stack.append([lastS, max(lastE, e)])
            else:
                stack.append([s, e])
        return stack