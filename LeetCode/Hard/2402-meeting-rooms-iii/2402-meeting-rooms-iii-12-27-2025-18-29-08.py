class Solution:
    def mostBooked(self, n: int, meetings: List[List[int]]) -> int:
        # (end_time, room_no)
        used_rooms, unused_rooms = [], [i for i in range(n)]
        heapify(unused_rooms)
        meetings.sort()
        meeting_count = [0] * n

        for start, end in meetings:
            
            while used_rooms and used_rooms[0][0] <= start:
                _, room = heappop(used_rooms)
                heappush(unused_rooms, room)

            if unused_rooms:
                room = heappop(unused_rooms)
                heappush(used_rooms, (end, room))
            else:
                e, room = heappop(used_rooms)
                heappush(used_rooms, (e + end - start, room))

            meeting_count[room] += 1

        return meeting_count.index(max(meeting_count))