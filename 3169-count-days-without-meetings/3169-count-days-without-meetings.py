class Solution:
    def countDays(self, days: int, meetings: List[List[int]]) -> int:
        heapify(meetings)
        ans, prev_end = 0, 0

        while meetings:
            start_i, end_i = heappop(meetings)
            
            if start_i > prev_end:
                ans += start_i - prev_end - 1
            prev_end = max(prev_end, end_i)
        
        return ans + max(0, days - prev_end)