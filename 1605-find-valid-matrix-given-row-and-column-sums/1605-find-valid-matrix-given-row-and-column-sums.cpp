class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size(), n = colSum.size();
        vector<vector<int>> matrix(m, vector<int>(n));
        vector<int> prefixR(m), prefixC(n);
        
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                matrix[i][j] = min(rowSum[i] - prefixR[i], colSum[j] - prefixC[j]);
                
                prefixR[i] += matrix[i][j];
                prefixC[j] += matrix[i][j];
            }
        }
        
        return matrix;
    }
};