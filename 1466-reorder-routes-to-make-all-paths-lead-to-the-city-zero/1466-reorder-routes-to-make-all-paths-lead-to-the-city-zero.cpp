class Solution {
private:
    int ans = 0;
    void bfs(int start, int n, vector<vector<pair<int, int>>>& adj){
        queue<int> queue;
        queue.push(start);
        vector<bool> visited(n);
        visited[start] = true;
        
        while (!queue.empty()){
            int node = queue.front();
            queue.pop();
            for (auto& [neighbor, sign] : adj[node]){
                if (!visited[neighbor]){
                    visited[neighbor] = true;
                    ans += sign;
                    queue.push(neighbor);
                }
            }
        }
    }
    
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);
        for(vector<int>& connection : connections){
            adj[connection[0]].push_back({connection[1], 1});
            adj[connection[1]].push_back({connection[0], 0});
        }
        
        bfs(0, n, adj);
        return ans;
    }
};