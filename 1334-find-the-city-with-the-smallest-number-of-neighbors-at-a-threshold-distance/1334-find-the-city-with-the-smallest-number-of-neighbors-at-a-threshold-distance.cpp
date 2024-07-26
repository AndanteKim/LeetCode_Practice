class Solution {
private:
    // Large value to represent infinity
    const int inf = 1e9 + 7;
    int n;
    
    // Bellman-Fod algorithm to find shortest paths from a source city
    void bellmanFord(vector<int>& distances, vector<vector<int>>& edges, int source){
        // Relax edges up to n - 1 times 
        for (int i = 0; i < n - 1; ++i){
            bool updated = false;
            for (vector<int>& edge : edges){
                int start = edge[0], end = edge[1], weight = edge[2];
                
                // Update the shortest path distances if a shorter path is found
                if (distances[start] != inf && distances[start] + weight < distances[end]){
                    distances[end] = distances[start] + weight;
                    updated = true;
                }
                
                if (distances[end] != inf && distances[end] + weight < distances[start]){
                    distances[start] = distances[end] + weight;
                    updated = true;
                }
            }
            if (!updated)
                break;
        }
    }
    
    // Determine the city with the fewest number of reachable cities within the
    // distance threshold
    int getCityWithFewestReachable(vector<vector<int>>& matrix, int threshold){
        int cityWithFewestReachable = -1, fewestReachableCount = n;
        
        // Count the number of cities reachable within the distance threshold for each city.
        for (int i = 0; i < n; ++i){
            int reachableCount = 0;
            for (int j = 0; j < n; ++j){
                if (i != j && matrix[i][j] <= threshold)
                    ++reachableCount;
            }
            
            // Update the city with the fewest reachable cities
            if (reachableCount <= fewestReachableCount){
                fewestReachableCount = reachableCount;
                cityWithFewestReachable = i;
            }
        }
        
        return cityWithFewestReachable;
    }
    
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        this -> n = n;
        // Matrix to store the shortest path distances from each city
        vector matrix(n, vector<int>(n, inf));
        
        // Initialize the shortest path matrix
        for (int i = 0; i < n; ++i)
            matrix[i][i] = 0;
        
        // Populate the matrix with initial edge weights
        for (vector<int>& edge : edges){
            int start = edge[0], end = edge[1], weight = edge[2];
            matrix[start][end] = weight;
            matrix[end][start] = weight;    // For undirected graph
        }
        
        // Compute the shortest paths from each city using Bellman-Fod algorithm
        for (int i = 0; i < n; ++i)
            bellmanFord(matrix[i], edges, i);
        
        // Find the city with the fewest number of cities within the distance threshold
        return getCityWithFewestReachable(matrix, distanceThreshold);
    }
};