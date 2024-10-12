class Solution:
    def minGroups(self, intervals: List[List[int]]) -> int:
        # Use a dictionary to store the points and their counts
        point_to_count = defaultdict(int)
        
        # Mark the starting and ending points in the dictionary
        for start, end in intervals:
            point_to_count[start] += 1      # Start of an interval
            point_to_count[end + 1] -= 1    # End of an interval (interval[1] + 1)
            
        concurrent, max_concurrent = 0, 0
        
        # Iterate over the sorted keys of the dictionary
        for point in sorted(point_to_count.keys()):
            concurrent += point_to_count[point]    # Update currently active intervals
            max_concurrent = max(max_concurrent, concurrent)    # Update max intervals
            
        return max_concurrent