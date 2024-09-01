class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        // Base case
        if (original.size() != m * n)
            return vector<vector<int>>{};
        
        vector<vector<int>> ans(m);
        
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                ans[i].push_back(original[i * n + j]);
            }
        }
        
        return ans;
    }
};