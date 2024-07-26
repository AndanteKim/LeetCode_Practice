class Solution:
    def findTheCity(self, n: int, edges: List[List[int]], distanceThreshold: int) -> int:
        self.n = n
        # Adjacency list to store the graph
        adj = [[] for _ in range(n)]
        
        # Matrix to store the shortest path distances from each city
        matrix = [[float("inf")] * n for _ in range(n)]
        
        # Initialize adjacency list and shortest path matrix
        for i in range(n):
            matrix[i][i] = 0    # Dist to itself is zero
            
        # Populate the adjacency list with edges
        for start, end, weight in edges:
            adj[start].append((end, weight))
            adj[end].append((start, weight))    # For undirected
            
        # Compute the shortest paths from each city using SPFA algorithm
        for i in range(n):
            self.spfa(adj, matrix[i], i)
            
        # Find the city with the fewest number of reachable cities within the distance threshold
        return self.get_city_with_fewest_reachable(matrix, distanceThreshold)
    
    # SPFA algorithm to find the shortest paths from a source city
    def spfa(self, adj: List[List[tuple]], distances: List[int], source: int) -> None:
        # Queue to process nodes with updated the shortest path distances
        queue = deque([source])
        update_count = [0] * self.n
        
        # Process nodes in queue
        while queue:
            curr_city = queue.popleft()
            for neighbor, weight in adj[curr_city]:
                if distances[neighbor] > distances[curr_city] + weight:
                    distances[neighbor] = distances[curr_city] + weight
                    queue.append(neighbor)
                    update_count[neighbor] += 1
                    
                    # Detect negative weight cycles
                    """
                    if update_count[neighbor] > n:
                        print("Negative weight cycle detected")
                    """
                    
    # Determine the city with the fewest number of reachable cities within the distance threshold
    def get_city_with_fewest_reachable(self, matrix: List[List[int]], threshold: int) -> int:
        city_with_fewest_reachable = -1
        fewest_reachable_count = self.n
        
        # Count the number of cities reachable within the distance threshold for each city
        for i in range(self.n):
            reachable_count = 0
            for j in range(self.n):
                if i != j and matrix[i][j] <= threshold:
                    reachable_count += 1
                    
            # Update the city with the fewest reachable cities
            if reachable_count <= fewest_reachable_count:
                fewest_reachable_count = reachable_count
                city_with_fewest_reachable = i
                
        return city_with_fewest_reachable