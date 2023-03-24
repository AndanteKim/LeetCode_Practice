class Solution {
    int count = 0;
    void bfs(int node, int n, vector<vector<pair<int, int>>>& adj){
        queue<int> *q = new queue<int>;
        vector<bool> visited(n, false);
        q -> push(node);
        visited[node] = true;
        
        while (!q -> empty()){
            int curr_node = q -> front();
            q -> pop();
            for (auto& [neighbor, sign] : adj[curr_node]){
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    count += sign;
                    q -> push(neighbor);
                }
            }
        }
        
    }
    
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);
        for (vector<int>& connection : connections){
            adj[connection[0]].push_back({connection[1], 1});
            adj[connection[1]].push_back({connection[0], 0});
        }
        
        bfs(0, n, adj);
        return count;
    }
};