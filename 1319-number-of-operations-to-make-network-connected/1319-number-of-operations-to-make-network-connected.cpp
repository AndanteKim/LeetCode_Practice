class Solution {
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited){
        visited[node] = true;
        for (int adjNode : adj[node]){
            if (!visited[adjNode]){
                dfs(adjNode, adj, visited);
            }
        }
    }
    
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1;
        
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);
        
        for (vector<int>& connection : connections){
            adj[connection[0]].push_back(connection[1]);
            adj[connection[1]].push_back(connection[0]);
        }
        
        int connected = 0;
        for (int node = 0; node < n; ++node){
            if (!visited[node]){
                ++connected;
                dfs(node, adj, visited);
            }
        }
        
        return connected - 1;
    }
};