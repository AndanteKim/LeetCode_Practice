class Solution:
    def minGroups(self, intervals: List[List[int]]) -> int:
        # Convert the intervals to two events
        # start as (start, 1) and end as (end + 1, -1)
        events = []
        
        for start, end in intervals:
            events.append((start, 1))     # Start event
            events.append((end + 1, -1))    # End event (end + 1)
            
        # Sort the events first by time, and then by type (1 for start, -1 for end).
        events.sort(key = lambda x: (x[0], x[1]))
        concurrent, max_concurrent = 0, 0
        
        # Sweep through the events
        for event in events:
            concurrent += event[1]  # Track currentl active intervals
            max_concurrent = max(max_concurrent, concurrent)    # Update max
            
        return max_concurrent