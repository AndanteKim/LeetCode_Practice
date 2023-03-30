class Solution {
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited){
        visited[node] = true;
        for(int neighbor : adj[node]){
            if(!visited[neighbor]) dfs(neighbor, adj, visited);
        }
    }
    
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool> visited(n, false);
        vector<vector<int>> adj(n);
        for(vector<int>& edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        dfs(source, adj, visited);
        return visited[destination];
    }
};