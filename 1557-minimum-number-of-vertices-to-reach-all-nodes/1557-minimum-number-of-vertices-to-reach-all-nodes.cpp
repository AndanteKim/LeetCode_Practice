class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> visited(n), ans;
        for (vector<int>& edge: edges) visited[edge[1]] = true;
        for (int node = 0; node < n; ++node) {
            if (!visited[node]) ans.push_back(node);
        }
        
        return ans;
    }
};