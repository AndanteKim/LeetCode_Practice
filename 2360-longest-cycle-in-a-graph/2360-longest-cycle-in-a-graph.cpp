class Solution {
    int ans = -1;
    
    void dfs(int node, vector<int>& edges, unordered_map<int, int>& dist, \
             vector<bool>& visited){
        visited[node] = true;
        int neighbor = edges[node];
        
        if (neighbor != -1 && !visited[neighbor]){
            dist[neighbor] = dist[node] + 1;
            dfs(neighbor, edges, dist, visited);
        }
        else if (neighbor != -1 && dist.count(neighbor) > 0){
            ans = max(ans, dist[node] - dist[neighbor] + 1);
        }
    }
    
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> visited(n, false);
        
        for (int node = 0; node < n; ++node){
            if (!visited[node]){
                unordered_map<int, int> dist;
                dist[node] = 1;
                dfs(node, edges, dist, visited);
            }
        }
        
        return ans;
    }
};