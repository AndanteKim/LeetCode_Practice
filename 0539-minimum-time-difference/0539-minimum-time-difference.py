class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        # Convert input to minutes
        minutes = []
        
        for time in timePoints:
            h, m = int(time[:2]), int(time[3:])
            minutes.append(60 * h + m)
        
        # sort times in ascending order
        minutes.sort()
        ans, n = float('inf'), len(minutes)
        
        # Find the minimum difference across adjacent elements
        for i in range(n - 1):
            ans = min(ans, minutes[i + 1] - minutes[i])
            
        # Consider difference between last and first element
        return min(ans, 24 * 60 - minutes[n - 1] + minutes[0])