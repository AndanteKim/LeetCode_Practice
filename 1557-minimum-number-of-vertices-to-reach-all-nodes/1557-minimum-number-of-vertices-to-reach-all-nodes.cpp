class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n), ans;
        for (vector<int>& edge: edges){
            ++indegree[edge[1]];
        }
        int mn = *min_element(indegree.begin(), indegree.end());
        
        for (int node = 0; node < n; ++node){
            if (indegree[node] == mn) ans.push_back(node);
        }
        
        return ans;
    }
};