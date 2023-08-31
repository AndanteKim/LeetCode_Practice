class Solution:
    def minTaps(self, n: int, ranges: List[int]) -> int:
        max_end = n
        
        intervals = sorted((max(0, i - r), min(n, i + r)) for i, r in enumerate(ranges))
        
        N = len(ranges)
        current_end = i = count = max_reachable_end = 0
        
        while current_end < max_end:
            
            while i < N and intervals[i][0] <= current_end:
                max_reachable_end = max(max_reachable_end, intervals[i][1])
                i += 1
            
            if current_end == max_reachable_end:
                return -1
            
            current_end = max_reachable_end
            count += 1
        
        return count