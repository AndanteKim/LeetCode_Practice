class Solution:
    def minGroups(self, intervals: List[List[int]]) -> int:
        # Find the minimum and maximum value in the intervals
        range_start, range_end = float('inf'), float('-inf')
        
        for start, end in intervals:
            range_start = min(range_start, start)
            range_end = max(range_end, end)
            
        # Initialize the list with all zeroes
        point_to_count = [0] * (range_end + 2)
        
        for start, end in intervals:
            point_to_count[start] += 1    # Increment at the start of the interval
            point_to_count[end + 1] -= 1    # Decrement right after the end of the interval
            
        concurrent, max_concurrent = 0, 0
        
        for i in range(range_start, range_end + 1):
            # Update currently active intervals
            concurrent += point_to_count[i]
            max_concurrent = max(max_concurrent, concurrent)
            
        return max_concurrent