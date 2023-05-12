class Solution:
    def mostBooked(self, n: int, meetings: List[List[int]]) -> int:
        meetings.sort()
        ready, rooms = [r for r in range(n)], []
        
        ans = [0] * n
        
        for start, end in meetings:
            while rooms and rooms[0][0] <= start:
                t, r = heappop(rooms)
                heappush(ready, r)
            if ready:
                r = heappop(ready)
                heappush(rooms, [end, r])
            else:
                t, r = heappop(rooms)
                heappush(rooms, [t + end - start, r])
            ans[r] += 1
            
        return ans.index(max(ans))