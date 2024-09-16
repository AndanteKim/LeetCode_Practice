class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        # Create buckets array for the times converted to minutes
        minutes = [False] * (24 * 60)
        
        for time in timePoints:
            h, m = map(int, time.split(":"))
            min_time = 60 * h + m
            
            if minutes[min_time]:
                return 0
            minutes[min_time] = True
            
        prev_idx, ans = float('inf'), float('inf')
        first_idx, last_idx = float('inf'), float('inf')
        
        # Find differences between adjacent elements in sorted array
        for i in range(24 * 60):
            if minutes[i]:
                if prev_idx != float('inf'):
                    ans = min(ans, i - prev_idx)
                prev_idx = i
                if first_idx == float('inf'):
                    first_idx = i
                last_idx = i
                
        return min(ans, 24 * 60 - last_idx + first_idx)