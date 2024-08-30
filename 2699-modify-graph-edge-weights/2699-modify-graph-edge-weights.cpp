typedef long long ll;

class Solution {
private:
    int INF = 2e9, n;
    
    ll dijkstra(vector<vector<pair<int, int>>>& graph, int source, int destination){
        vector<ll> minDist(n, INF);
        minDist[source] = 0;
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> minHeap;
        
        minHeap.push({0, source});  // (distance, node)
        
        while (!minHeap.empty()){
            auto [d, u] = minHeap.top();
            minHeap.pop();
            
            if (d > minDist[u])
                continue;
            
            for (auto& [v, w] : graph[u]){
                if (d + w < minDist[v]){
                    minDist[v] = d + w;
                    minHeap.push({minDist[v], v});
                }
            }
        }
        
        return minDist[destination];
    }
    
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        this -> n = n;
        vector<vector<pair<int, int>>> graph(n);
        
        // Build the graph with known weights
        for (const auto& edge : edges){
            if (edge[2] != -1){
                graph[edge[0]].push_back({edge[1], edge[2]});
                graph[edge[1]].push_back({edge[0], edge[2]});
            }
        }
        
        // Compute the initial shortest distance from source to destination
        ll currentShortestDistance = dijkstra(graph, source, destination);
        if (currentShortestDistance < target)
            return vector<vector<int>>{};
        
        if (currentShortestDistance == target){
            // Update edges with -1 weight to an impossible value
            for (auto& edge : edges){
                if (edge[2] == -1){
                    edge[2] = INF;
                }
            }
            return edges;
        }
        
        // Adjust edges with unknown weights
        for (int i = 0; i < edges.size(); ++i){
            if (edges[i][2] != -1) continue;
            
            // Set edge weight to 1 initially
            edges[i][2] = 1;
            graph[edges[i][0]].push_back({edges[i][1], 1});
            graph[edges[i][1]].push_back({edges[i][0], 1});
            
            // Recompute shortest distance with updated edge weight
            ll newDistance = dijkstra(graph, source, destination);
            
            if (newDistance <= target){
                edges[i][2] += target - newDistance;
                
                // Update remaining edges with -1 weight to an impossible value
                for (int j = i + 1; j < edges.size(); ++j){
                    if (edges[j][2] == -1)
                        edges[j][2] = INF;
                }
                return edges;
            }
        }
        
        return vector<vector<int>>{};
    }
};