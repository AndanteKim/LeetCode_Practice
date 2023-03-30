class Solution {
    int ans = 0;
    
public:
    void dfs(int node, vector<vector<pair<int, int>>>& adj, vector<bool>& visited){
        visited[node] = true;
        for (const auto& [neighbor, score] : adj[node]){
            if(!visited[neighbor]){
                ans += score;
                dfs(neighbor, adj, visited);
            }
        }
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);
        vector<bool> visited(n);
        
        for (const vector<int>& connection : connections){
            adj[connection[0]].push_back({connection[1], 1});
            adj[connection[1]].push_back({connection[0], 0});
        }
        
        for (int node = 0; node < n; ++node){
            if(!visited[node]) dfs(node, adj, visited);
        }
        
        return ans;
    }
};