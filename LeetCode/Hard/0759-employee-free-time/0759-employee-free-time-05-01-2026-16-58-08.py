"""
# Definition for an Interval.
class Interval:
    def __init__(self, start: int = None, end: int = None):
        self.start = start
        self.end = end
"""

class Solution:
    def employeeFreeTime(self, schedule: '[[Interval]]') -> '[Interval]':
        times = []
        for s in schedule:
            for it in s:
                times.append([it.start, it.end])

        times.sort()
        ans = []
        prev_s, prev_e = -1, -1
        
        for s, e in times:
            if prev_e != -1 and prev_e < s:
                ans.append(Interval(prev_e, s))
            
            prev_s, prev_e = s, max(prev_e, e)

        return ans