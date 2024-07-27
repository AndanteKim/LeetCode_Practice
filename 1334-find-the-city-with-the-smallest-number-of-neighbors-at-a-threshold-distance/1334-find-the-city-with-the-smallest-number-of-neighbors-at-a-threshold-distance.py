class Solution:
    def findTheCity(self, n: int, edges: List[List[int]], distanceThreshold: int) -> int:
        # Large value to represent infinity
        inf = int(1e9) + 7
        
        # Distance matrix to store shortest paths between all pairs of cities
        matrix = []
        
        # Initialize distance matrix
        for i in range(n):
            matrix.append([inf] * n)
            matrix[i][i] = 0    # Distance to itself is zero
            
        # Populate the distance matrix with the initial edge weights
        for start, end, weight in edges:
            matrix[start][end] = weight
            matrix[end][start] = weight     # For undirected graph
            
        # Compute shortest paths using Floyd-Warshall algorithm
        self.floyd(n, matrix)
        
        # Find the city with the fewest number of reacahable cities within the distance threshold
        return self.get_city_with_fewest_reachable(n, matrix, distanceThreshold)
    
    # Floyd-Warshall algorithm to compute shortest paths between all pairs of cities
    def floyd(self, n: int, distances: List[List[int]]) -> None:
        # Update distances for each intermediate city
        for k in range(n):
            for i in range(n):
                for j in range(n):
                    # Update shortest path from i to j through k
                    distances[i][j] = min(distances[i][j], distances[i][k] + distances[k][j])
    
    # Determine the city with the fewest number of reachable cities within the distance threshold
    def get_city_with_fewest_reachable(self, n: int, distances: List[List[int]], threshold: int) -> int:
        city_with_fewest_reachble = -1
        fewest_reachable_count = n
        
        # Count number of cities reachable within the distance threshold for each city
        for i in range(n):
            reachable_count = 0
            
            for j in range(n):
                if distances[i][j] <= threshold:
                    reachable_count += 1
            
            # Update the city with the fewest reachable cities
            if reachable_count <= fewest_reachable_count:
                fewest_reachable_count = reachable_count
                city_with_fewest_reachable = i
                
        return city_with_fewest_reachable