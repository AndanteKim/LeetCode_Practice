class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> ans;
        vector<pair<int, int>> candidates;
        pair<int, int> curr;
        
        for (int i = 0; i < m; ++i){
            int minRow = INT_MAX;
            curr = {0, 0};
            
            for (int j = 0; j < n; ++j){
                if (minRow > matrix[i][j]){
                    curr = {i, j};
                    minRow = matrix[i][j];
                }
            }
            
            candidates.push_back(curr);
        }
        
        for (auto& [i, j] : candidates){
            int maxCol = INT_MIN;
            curr = {0, 0};
            for (int k = 0; k < m; ++k){
                if (maxCol < matrix[k][j]){
                    curr = {k, j};
                    maxCol = matrix[k][j];
                }
            }
            
            if (matrix[i][j] == maxCol)
                ans.push_back(matrix[i][j]);
        }
        
        return ans;
    }
};