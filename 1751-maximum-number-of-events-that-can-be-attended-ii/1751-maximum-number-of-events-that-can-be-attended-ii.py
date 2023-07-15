class Solution:
    def maxValue(self, events: List[List[int]], k: int) -> int:
        events.sort(key = lambda x: x[0])
        
        @lru_cache(maxsize = None)
        def dp(prev: int, start: int, k: int) -> int:
            if start >= len(events) or k == 0:
                return 0
            
            curr = 0
            if prev == -1 or events[prev][1] < events[start][0]:
                curr += max(events[start][2] + dp(start, start + 1, k - 1), dp(prev, start + 1, k))
            else:
                curr += dp(prev, start + 1, k)
            
            return curr
            
        
        return dp(-1, 0, k)
        