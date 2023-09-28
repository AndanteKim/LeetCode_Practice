class Solution {
private:
    int ans = 0;
    void dfs(int node, int parent, vector<vector<pair<int, int>>>& adj){
        for (auto& [child, sign] : adj[node]){
            if (child != parent){
                ans += sign;
                dfs(child, node, adj);
            }
        }
    }
    
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);
        
        for (vector<int>& connection : connections){
            adj[connection[0]].push_back(make_pair(connection[1], 1));
            adj[connection[1]].push_back(make_pair(connection[0], 0));
        }
        
        dfs(0, -1, adj);
        return ans;
    }
};