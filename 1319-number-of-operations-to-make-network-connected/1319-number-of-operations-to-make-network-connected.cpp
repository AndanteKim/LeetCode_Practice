class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1;
        
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);
        
        for (auto& connection : connections){
            adj[connection[0]].push_back(connection[1]);
            adj[connection[1]].push_back(connection[0]);
        }
        
        int connected = 0;
        for (int node = 0; node < n; ++node){
            if (!visited[node]){
                ++connected;
                visited[node] = true;
                
                queue<int> *q = new queue<int>;
                q -> push(node);
                while (!q -> empty()){
                    int curr = q -> front();
                    q -> pop();
                    for(int neighbor : adj[curr]){
                        if (!visited[neighbor]){
                            visited[neighbor] = true;
                            q -> push(neighbor);
                        }
                    }
                }
            }
        }
        
        return connected - 1;
    }
};