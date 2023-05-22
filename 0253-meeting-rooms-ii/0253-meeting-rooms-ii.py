class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        used_rooms = 0
        
        start_time = sorted([interval[0] for interval in intervals])
        end_time = sorted([interval[1] for interval in intervals])
        n = len(intervals)
        
        start_ptr, end_ptr = 0, 0
        
        while start_ptr < n:
            if start_time[start_ptr] >= end_time[end_ptr]:
                used_rooms -= 1
                end_ptr += 1
            
            used_rooms += 1
            start_ptr += 1
        return used_rooms