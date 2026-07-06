class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        if len(intervals) <= 1:
            return len(intervals)
        intervals.sort(key = lambda x: (x[0], -x[1]))
        n = len(intervals)
        ans, i = n, 0
        
        while i < n - 1:
            c, d = intervals[i]
            j = i + 1

            while j < n:
                a, b = intervals[j]
                if c <= a and b <= d:
                    ans -= 1
                    j += 1
                else:
                    break
            i = j

        return ans