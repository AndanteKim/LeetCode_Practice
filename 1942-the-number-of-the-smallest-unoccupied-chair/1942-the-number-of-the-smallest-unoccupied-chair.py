class Solution:
    def smallestChair(self, times: List[List[int]], targetFriend: int) -> int:
        # To store both arrival and leave events
        n, events = len(times), []
        
        # Populate events with arrival and leave times
        for i in range(n):
            # Arrival and leave
            events.append((times[i][0], i))
            events.append((times[i][1], ~i))
        
        # Sort events by time
        events.sort()
        
        # Tracking chairs that are free.
        available_chairs = [i for i in range(n)]
        
        # When each chair will be free
        occupied_chairs = []
        
        for event in events:
            time, friend = event
            
            # free up chairs if friends leave
            while occupied_chairs and occupied_chairs[0][0] <= time:
                # Pop chair that becomes empty
                _, chair = heappop(occupied_chairs)
                
                # Available chairs
                heappush(available_chairs, chair)
            
            # If friend arrives
            if friend >= 0:
                chair = heappop(available_chairs)
                if friend == targetFriend:
                    return chair
                
                # Chair will be occupied till this time
                heappush(occupied_chairs, (times[friend][1], chair))
                
        # Should not come to this point 
        return -1