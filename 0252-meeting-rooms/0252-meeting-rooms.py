class Solution:
    def canAttendMeetings(self, intervals: List[List[int]]) -> bool:
        intervals.sort()
        current = [0, 0]
        for start, end in intervals:
            if current[1] > start:
                return False
            current = [start, end]
        
        return True