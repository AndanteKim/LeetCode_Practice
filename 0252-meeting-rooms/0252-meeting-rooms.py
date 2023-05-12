class Solution:
    def canAttendMeetings(self, intervals: List[List[int]]) -> bool:
        if len(intervals) == 0:
            return True
        intervals.sort()
        prev = intervals[0]
        for i in range(1, len(intervals)):
            if prev[1] > intervals[i][0]:
                return False
            prev = intervals[i]
        return True