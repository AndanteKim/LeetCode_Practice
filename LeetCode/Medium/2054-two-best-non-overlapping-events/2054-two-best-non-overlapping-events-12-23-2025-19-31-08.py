class Solution:
    def maxTwoEvents(self, events: List[List[int]]) -> int:
        def dp(i: int, cnt: int) -> int:
            # Base case
            if cnt == 2 or i == n:
                return 0

            if memo[i][cnt] == -1:
                start, end, val = events[i]
                lo, hi = i + 1, n - 1
                
                while lo < hi:
                    mid = lo + ((hi - lo) >> 1)
                    if events[mid][0] > end:
                        hi = mid
                    else:
                        lo = mid + 1
                include = val + (
                    dp(lo, cnt + 1)
                    if lo < n and events[lo][0] > end
                    else 0
                )
                exclude = dp(i + 1, cnt)
                memo[i][cnt] = max(include, exclude)

            return memo[i][cnt]
        
        events.sort()
        n = len(events)
        memo = [[-1] * 3 for _ in range(n)]
        return dp(0, 0)