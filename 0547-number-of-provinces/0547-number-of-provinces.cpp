class Solution {
    void dfs(int node, vector<vector<int>>& isConnected, vector<bool>& visited){
        visited[node] = true;
        for (int neighbor = 0; neighbor < isConnected[node].size(); ++neighbor){
            if (!visited[neighbor] && isConnected[node][neighbor] == 1 && node != neighbor)
                dfs(neighbor, isConnected, visited);
        }
    }
    
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), ans = 0;
        vector<bool> visited(n);
        for (int node = 0; node < n; ++node){
            if (!visited[node]){
                dfs(node, isConnected, visited);
                ++ans;
            }
        }
        
        return ans;
    }
};