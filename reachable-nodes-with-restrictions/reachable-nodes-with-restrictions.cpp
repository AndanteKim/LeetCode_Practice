class Solution {
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited){
        visited[node] = true;
        
        for (int neighbor : adj[node]){
            if (!visited[neighbor])
                dfs(neighbor, adj, visited);
        }
    }
    
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<bool> visited(n), filtered(n);
        vector<vector<int>> adj(n);
        
        for (int node : restricted){
            filtered[node] = true;
        }
        
        for (const vector<int>& edge : edges){
            if (filtered[edge[0]] || filtered[edge[1]]) continue;
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        dfs(0, adj, visited);
        
        return count(visited.begin(), visited.end(), true);
    }
};