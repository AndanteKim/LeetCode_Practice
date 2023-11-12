class Solution:
    def numBusesToDestination(self, routes: List[List[int]], source: int, target: int) -> int:
        def have_common_node(route1: List[int], route2: List[int]) -> bool:
            i, j = 0, 0
            while i < len(route1) and j < len(route2):
                if route1[i] == route2[j]:
                    return True
            
                if route1[i] < route2[j]:
                    i += 1
                else:
                    j += 1
            return False
        
        # Return true if the given stop is present in the route, False otherwise
        def is_stop_exist(route: List[int], stop: int) -> bool:
            for j in range(len(route)):
                if route[j] == stop:
                    return True
            return False
    
        
        if source == target:
            return 0
        
        for i in range(len(routes)):
            routes[i].sort()
        
        adj_list = [[] for _ in range(501)]
        for i in range(len(routes)):
            for j in range(i + 1, len(routes)):
                if have_common_node(routes[i], routes[j]):
                    adj_list[i].append(j)
                    adj_list[j].append(i)
        
        queue = deque()
        for i in range(len(routes)):
            if is_stop_exist(routes[i], source):
                queue.append(i)
        
        visited = [False] * len(routes)
        bus_count = 1
        
        while queue:
            size = len(queue)
            
            while size > 0:
                node = queue.popleft()
                
                # Return bus_count, if the stop target is present in the current route
                if is_stop_exist(routes[node], target):
                    return bus_count
            
                # Add the adjacent routes
                for adj in adj_list[node]:
                    if not visited[adj]:
                        visited[adj] = True
                        queue.append(adj)
                size -= 1
                
            bus_count += 1
        return -1
        