class Solution:
    def findTheCity(self, n: int, edges: List[List[int]], distanceThreshold: int) -> int:
        self.n = n
        # Large value to represent infinity
        inf = int(1e9) + 7
        
        # Matrix to store the shortest path distances from each city
        matrix = [[inf] * n for _ in range(n)]
        
        # Initialize the shortest path matrix
        for i in range(n):
            matrix[i][i] = 0
            
        # Populate the matrix with initial edge weights
        for start, end, weight in edges:
            matrix[start][end] = weight
            matrix[end][start] = weight # For undirected graph
            
        # Compute the shortest paths from each city using Bellman-Ford algorithm
        for i in range(n):
            self.bellman_ford(edges, matrix[i], i)
            
        # Find the city with the fewest number of reachable cities within the distance threshold
        return self.getCityWithFewestReachable(matrix, distanceThreshold)
    
    # Bellman-Ford algorithm to find the shortest paths from a source city
    def bellman_ford(self, edges: List[List[int]], distances: List[int], source: int) -> None:
        # Initialize distances from the source
        distances[:] = [float('inf')] * self.n
        distances[source] = 0   # Distance to source itself is zero
        
        # Relax edges up to n - 1 times with early stopping
        for _ in range(self.n - 1):
            updated = False
            for start, end, weight in edges:
                if distances[start] != float('inf') and distances[start] + weight < distances[end]:
                    distances[end] = distances[start] + weight
                    updated = True
                    
                if distances[end] != float('inf') and distances[end] + weight < distances[start]:
                    distances[start] = distances[end] + weight
                    updated = True
                    
            if not updated:
                break   # Stop early if no updates
            
    # Determine the city with the fewest number of reachable cities within the distance threshold
    def getCityWithFewestReachable(self, matrix: List[List[int]], threshold: int) -> int:
        cityWithFewestReachable = -1
        fewestReachableCount = self.n
        
        # Count number of cities reachable within the distance threshold for each city
        for i in range(self.n):
            reachableCount = 0
            for j in range(self.n):
                if i != j and matrix[i][j] <= threshold:
                    reachableCount += 1
                    
            # Update the city with the fewest reachable cities
            if reachableCount <= fewestReachableCount:
                fewestReachableCount = reachableCount
                cityWithFewestReachable = i
                
        return cityWithFewestReachable