class Solution:
    def minGroups(self, intervals: List[List[int]]) -> int:
        intervals.sort()
        ends, min_groups = [], 0
        
        for start, end in intervals:
            while ends and ends[0] < start:
                heappop(ends)
                
            heappush(ends, end)
            min_groups = max(min_groups, len(ends))
            
        return min_groups