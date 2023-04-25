class Solution {
    void dfs(int start, int curr, vector<vector<int>>& adj, vector<vector<int>>& ans){
        for (int neighbor : adj[curr]){
            if (!ans[neighbor].empty() && ans[neighbor].back() == start) continue;
            ans[neighbor].push_back(start);
            dfs(start, neighbor, adj, ans);
        }
    }
    
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector adj(n, vector<int>()), ans(n, vector<int>());
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
        }
        
        for (int node = 0; node < n; ++node)
            dfs(node, node, adj, ans);
        return ans;
    }
};