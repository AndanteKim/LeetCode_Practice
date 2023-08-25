class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()
        ans = []
        for start, end in intervals:
            if not ans or ans[-1][1] < start:
                ans.append([start, end])
                
            else:
                ans[-1][0] = min(ans[-1][0], start)
                ans[-1][1] = max(ans[-1][1], end)
                
        return ans