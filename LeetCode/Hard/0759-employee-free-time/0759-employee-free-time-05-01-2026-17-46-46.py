"""
# Definition for an Interval.
class Interval:
    def __init__(self, start: int = None, end: int = None):
        self.start = start
        self.end = end
"""

class Solution:
    def employeeFreeTime(self, schedule: '[[Interval]]') -> '[Interval]':
        ans = []
        pq = [(emp[0].start, ei, 0) for ei, emp in enumerate(schedule)]
        heapify(pq)
        anchor = min(iv.start for emp in schedule for iv in emp)

        while pq:
            t, e_id, e_jx = heappop(pq)
            if anchor < t:
                ans.append(Interval(anchor, t))
            
            anchor = max(anchor, schedule[e_id][e_jx].end)
            if e_jx + 1 < len(schedule[e_id]):
                heappush(pq, (schedule[e_id][e_jx + 1].start, e_id, e_jx + 1))

        return ans