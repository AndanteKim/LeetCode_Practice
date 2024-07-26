class Solution {
private:
    int n;
    
    // SPFA algorithm to find the shortest paths from a source city
    void spfa(vector<vector<pair<int, int>>>& adj, vector<int>& distances, int source){
        // Queue to process nodes with updated shortest path distances
        queue<int> queue;
        queue.push(source);
        vector<int> updateCount(n, 0);
        
        // Process nodes in queue
        while (!queue.empty()){
            int currCity = queue.front(); queue.pop();
            
            for (auto& [neighbor, weight] : adj[currCity]){
                if (distances[neighbor] > distances[currCity] + weight){
                    distances[neighbor] = distances[currCity] + weight;
                    queue.push(neighbor);
                    ++updateCount[neighbor];
                    
                    // Detect negative weight cycles (not expected in this problem).
                    if (updateCount[neighbor] > n)
                        cout << "Negative cycle detected" << "\n";
                }
            }
        }
    }
    
    // Determine the city with the fewest number of reachable cities within the
    // distances threshold
    int getCityWithFewestReachable(vector<vector<int>>& matrix, int threshold){
        int cityWithFewestReachable = -1;
        int fewestReachableCount = n;
        
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
                cityWithFewestReachable = i;
            }
        }
        
        return cityWithFewestReachable;
    }
    
    
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Adjacency list to store the graph
        this -> n = n;
        vector adj(n, vector<pair<int, int>>());
        
        // Matrix to store the shortest path distances from each city
        vector matrix(n, vector<int>(n, 1e9 + 7));
        
        // Intialize adjacency list and the shortest path
        for (int i = 0; i < n; ++i)
            matrix[i][i] = 0;   // Distance to itself is zero
        
        // Populate the adjacency list with edges
        for (vector<int>& edge : edges){
            int start = edge[0], end = edge[1], weight = edge[2];
            adj[start].push_back({end, weight});
            adj[end].push_back({start, weight});    // For Undirected graph
        }
        
        
        // Compute the shortest paths from each city using SPFA algorithm
        for (int i = 0; i < n; ++i)
            spfa(adj, matrix[i], i);
        
        // Find the city with the fewest number of reachable cities within the
        // distance threshold
        return getCityWithFewestReachable(matrix, distanceThreshold);
    }
};