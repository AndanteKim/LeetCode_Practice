class Solution:
    def maxValue(self, events: List[List[int]], k: int) -> int:
        def dp(curr_idx: int, cnt: int) -> int:
            # Base case
            if cnt == 0 or curr_idx == n:
                return 0

            if memo[curr_idx][cnt] != -1:
                return memo[curr_idx][cnt]
            
            # Find the nearest available events after attending event 0.
            next_idx = bisect_right(starts, events[curr_idx][1])
            memo[curr_idx][cnt] = max(dp(curr_idx + 1, cnt), events[curr_idx][2] + dp(next_idx, cnt - 1))
            return memo[curr_idx][cnt]
        
        
        events.sort()
        n = len(events)
        starts = [start for start, end, val in events]
        memo = [[-1] * (k + 1) for _ in range(n)]
        
        return dp(0, k)