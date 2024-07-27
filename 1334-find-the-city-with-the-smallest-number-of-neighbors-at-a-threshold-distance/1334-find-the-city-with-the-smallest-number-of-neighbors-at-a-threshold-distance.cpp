class Solution {
private:
    // Floyd-Warshall algorithm to compute shortest paths between all pairs of
    // cities
    void floyd(int n, vector<vector<int>>& distances){
        // Update distances for each intermediate city
        for (int k = 0; k < n; ++k){
            for (int i = 0; i < n; ++i){
                for (int j = 0; j < n; ++j){
                    // Update shortest paths from i to j through k
                    distances[i][j] = min(distances[i][j], distances[i][k] + distances[k][j]);
                }
            }
        }
    }
    
    // Determine the city with the fewest number of reachable cites within the
    // distance threshold
    int getCityWithFewestReachable(int n, vector<vector<int>>& distances, int threshold){
        int cityWithFewestReachable = -1, fewestReachableCount = n;
        
        // Count number of cities reachable within the distance threshold for
        // each city
        for (int i = 0; i < n; ++i){
            int reachableCount = 0;
            for (int j = 0; j < n; ++j){
                if (distances[i][j] <= threshold)
                    ++reachableCount;
            }
            
            // Update the city with the fewest reachable cities
            if (reachableCount <= fewestReachableCount){
                cityWithFewestReachable = i;
                fewestReachableCount = reachableCount;
            }
        }
        
        return cityWithFewestReachable;
    }
    
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Larger value to represent infinity
        const int INF = 1e9 + 7;
        
        // Distance matrix to store shortest paths between all pairs of cities
        vector matrix(n, vector<int> (n, INF));
        
        // Initialize distance matrix
        for (int i = 0; i < n; ++i) matrix[i][i] = 0;   // Distance to itself is zero
        
        // Populate the distance matrix with initial edge weights
        for (vector<int>& edge : edges){
            int start = edge[0], end = edge[1], weight = edge[2];
            matrix[start][end] = weight;
            matrix[end][start] = weight;    // For Undirected graph
        }
        
        // Compute shortest paths using Floyd-Warshall algorithm
        floyd(n, matrix);
        
        // Find the city with the fewest number of reachable cities within the
        // distance threshold
        return getCityWithFewestReachable(n, matrix, distanceThreshold);
    }
};