class Solution:
    def maxTwoEvents(self, events: List[List[int]]) -> int:
        # Recursive function to find the greatest sum for the pairs
        def find_events(idx: int, cnt: int, dp: List[List[int]]) -> int:
            if cnt == 2 or idx == n:
                return 0
            
            if dp[idx][cnt] != -1:
                return dp[idx][cnt]
            
            end, lo, hi = events[idx][1], 0, n
            
            while lo < hi:
                mid = lo + ((hi - lo) >> 1)
                if events[mid][0] > end:
                    hi = mid
                else:
                    lo = mid + 1
            include = events[idx][2] + find_events(lo, cnt + 1, dp)
            exclude = find_events(idx + 1, cnt, dp)
            dp[idx][cnt] = max(include, exclude)
            
            return dp[idx][cnt]
        
        
        n = len(events)
        dp = [[-1] * 3 for _ in range(n)]
        events.sort()
        
        return find_events(0, 0, dp)