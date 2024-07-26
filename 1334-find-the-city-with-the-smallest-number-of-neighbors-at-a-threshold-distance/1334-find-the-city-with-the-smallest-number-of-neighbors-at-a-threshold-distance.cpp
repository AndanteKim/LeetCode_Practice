class Solution {
private:
    int n;
    
    // Dijkstra's algorithm to find the shortest paths from a source city
    void dijkstra(vector<int>& distances, const vector<vector<pair<int, int>>>& adj, int source){
        // Priority queue to process nodes with the smallest distance first
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, source});
        
        //Process nodes in priority order
        while (!pq.empty()){
            auto [currDist, currCity] = pq.top(); pq.pop();
            
            if (currDist > distances[currCity])
                continue;
            
            // Update distances to neighboring cities
            for (const auto& [neighbor, weight] : adj[currCity]){
                if (distances[neighbor] > currDist + weight){
                    distances[neighbor] = currDist + weight;
                    pq.push({currDist + weight, neighbor});
                }
            }
        }
    }
    
    // Determine the city with the fewest number of reachable cities within the
    // distance threshold
    int cityWithFewestReachable(vector<vector<int>>& matrix, int threshold){
        int fewestReachableCount = n, cityWithReachable = -1;
        
        // Count number of cities reachable within the distance threshold for
        // each city
        for (int i = 0; i < n; ++i){
            int reachableCount = 0;
            for (int j = 0; j < n; ++j){
                if (i != j && matrix[i][j] <= threshold)
                    ++reachableCount;
            }
            
            // Update the city with the fewest reachable cities
            if (reachableCount <= fewestReachableCount){
                fewestReachableCount = reachableCount;
                cityWithReachable = i;
            }
        }
        
            
        return cityWithReachable;
    }
    
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Adjacency list to store the graph
        vector<vector<pair<int, int>>> adj(n);
        this -> n = n;
        
        // Populate the adjacency list with edges
        for (const auto& edge : edges){
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]}); // For undirected graph
        }
        
        // Matrix to store the shortest path distances from each city.
        vector matrix(n, vector<int>(n, INT_MAX));
        
        // Initialize adjacency list and shortest path matrix.
        for (int i = 0; i < n; ++i)
            matrix[i][i] = 0;   // Distance to itself is zero
        
        // Compute the shortest paths from each city using Dijkstra's algorithm
        for (int node = 0; node < n; ++node)
            dijkstra(matrix[node], adj, node);  
        
        // Find the city with the fewest number of reachable cities within the
        // distance threshold
        return cityWithFewestReachable(matrix, distanceThreshold);
    }
};