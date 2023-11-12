class Solution:
    def numBusesToDestination(self, routes: List[List[int]], source: int, target: int) -> int:
        if source == target:
            return 0
        
        # key: bus stop, value : route number
        adj_list = defaultdict(list)
        
        # create a map from the bus stop to all the route that include this stop
        for route in range(len(routes)):
            for stop in routes[route]:
                adj_list[stop].append(route)
                
        queue, visited = deque(), set()
        # insert all the routes in the queue having the source stop
        for route in adj_list[source]:
            queue.append(route)
            visited.add(route)
        
        bus_count = 1
        while queue:
            size = len(queue)
            
            for i in range(size):
                route = queue.popleft()
                
                # iterate over the stops in the current route
                for stop in routes[route]:
                    # return the current count if the target is found
                    if stop == target:
                        return bus_count
                    
                    # iterate over the next possible routes from the current stop
                    for next_route in adj_list[stop]:
                        if next_route not in visited:
                            visited.add(next_route)
                            queue.append(next_route)
            
            bus_count += 1
        
        return -1