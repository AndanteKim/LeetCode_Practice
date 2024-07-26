class Solution:
    # Dijkstra's algorithm to find shortest paths from a source city
    def dijkstra(self, n: int, adj: List[List[tuple]], distances: List[int], source: int) -> None:
        # Priority queue to process nodes with the smallest distance first
        pq = [(0, source)]
        distances[:] = [float('inf')] * n
        distances[source] = 0    # Distance to itself is zero
        # Process nodes in priority order
        while pq:
            curr_dist, curr_city = heappop(pq)
            if curr_dist > distances[curr_city]:
                continue
                
            # Update distances to neighboring cities
            for neighbor, w in adj[curr_city]:
                if distances[neighbor] > curr_dist + w:
                    distances[neighbor] = curr_dist + w
                    heappush(pq, (distances[neighbor], neighbor))
                    
    # Determine the city with the fewest number of reachable cities within the distance threshold
    def get_city_with_fewest_reachable(self, n: int, matrix: List[List[int]], threshold: int) -> int:
        city_with_fewest_reachable = -1
        fewest_reachable_cnt = n
        
        # Count number of cities reachable within the distance threshold for each city
        for i in range(n):
            reachable_cnt = 0
            for j in range(n):
                if i != j and matrix[i][j] <= threshold:
                    reachable_cnt += 1
                    
            # Update the city with the fewest reachable cities
            if reachable_cnt <= fewest_reachable_cnt:
                fewest_reachable_cnt = reachable_cnt
                city_with_fewest_reachable = i
                
        return city_with_fewest_reachable
        
    
    def findTheCity(self, n: int, edges: List[List[int]], distanceThreshold: int) -> int:
        # Adjacency list to store the graph
        adj = [[] for _ in range(n)]
        
        # Matrix to store the shortest path distances from each city
        shortest_path = [[float("inf")] * n for _ in range(n)]
        
        # Initialize adjacency list and shortest path matrix
        for i in range(n):
            shortest_path[i][i] = 0 # Distance to itself it zero
        
        # Populate the adjacency list with edges for undirected graph
        for start, end, weight in edges:
            adj[start].append((end, weight))
            adj[end].append((start, weight))
            
        # Compute the shortest paths from each city using Dijkstra's algorithm
        for i in range(n):
            self.dijkstra(n, adj, shortest_path[i], i)
        
        # Find the city with the fewest number of reachable cities within the distance threshold
        return self.get_city_with_fewest_reachable(n, shortest_path, distanceThreshold)
    
    