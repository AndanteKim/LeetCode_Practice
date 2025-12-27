class Solution:
    def mostBooked(self, n: int, meetings: List[List[int]]) -> int:
        # (end_time, room_no)
        available, curr_rooms = [(0, i) for i in range(n)], []
        heapify(available)
        meetings.sort()
        freq, end_time = {i: 0 for i in range(n)}, {i: 0 for i in range(n)}

        for start, end in meetings:
            
            while available and available[0][0] <= start:
                _, room_no = heappop(available)
                heappush(curr_rooms, room_no)

            if curr_rooms:
                room = heappop(curr_rooms)
                end_time[room] = max(end_time[room] + end - start, end)
            else:
                e, room = heappop(available)
                end_time[room] = e + end - start

            freq[room] += 1
            heappush(available, (end_time[room], room))

        print(freq)
        ans, max_meetings = float('inf'), 0
        for room_no, num in freq.items():
            if max_meetings < num:
                max_meetings = num
                ans = room_no
            elif max_meetings == num:
                ans = min(ans, room_no)
        
        return ans