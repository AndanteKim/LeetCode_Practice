class Solution {
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited){
        visited[node] = true;
        
        for (int neighbor : adj[node]){
            if (!visited[neighbor]) dfs(neighbor, adj, visited);
        }
    }
    
    bool isSimilar(string& a, string& b){
        int diff = 0;
        for (int i = 0; i < a.size(); ++i){
            if (a[i] != b[i]) ++diff;
        }
        
        return diff == 0 || diff == 2;
    }
    
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        vector adj(n, vector<int>(n));
        for (int i = 0; i < n; ++i){
            for (int j = i + 1; j < n; ++j){
                if (isSimilar(strs[i], strs[j])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        vector<bool> visited(n);
        int ans = 0;
        for (int i = 0; i < n; ++i){
            if (!visited[i]) {
                dfs(i, adj, visited);
                ++ans;
            }
        }
        
        return ans;
    }
};