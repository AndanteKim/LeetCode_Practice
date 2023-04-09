class Solution {
    int dfs(int node, string& colors, vector<vector<int>>& adj, vector<vector<int>>& count,\
           vector<bool>& visited, vector<bool>& inStack){
        if (inStack[node]) return INT_MAX;
        if (visited[node])
            return count[node][colors[node] - 'a'];
        
        visited[node] = true;
        inStack[node] = true;
        for (int neighbor : adj[node]){
            if (dfs(neighbor, colors, adj, count, visited, inStack) == INT_MAX) return INT_MAX;
            for (int i = 0; i < 26; ++i) count[node][i] = max(count[node][i], count[neighbor][i]);
        }
        ++count[node][colors[node] - 'a'];
        inStack[node] = false;
        return count[node][colors[node] - 'a'];
    }
    
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size(), ans = 0;
        vector<vector<int>> adj(n);
        for (auto& edge: edges) adj[edge[0]].push_back(edge[1]);
        vector<vector<int>> count(n, vector<int>(26));
        vector<bool> visited(n), inStack(n);
        
        for (int i = 0; i < n; ++i)
            ans = max(ans, dfs(i, colors, adj, count, visited, inStack));
        return ans == INT_MAX? -1 : ans;
    }
};