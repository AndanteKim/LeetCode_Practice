class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size(), n = colSum.size();
        int i = 0, j = 0;
        vector<vector<int>> matrix(m, vector<int>(n));
        
        while (i < m && j < n){
            matrix[i][j] = min(rowSum[i], colSum[j]);
            rowSum[i] -= matrix[i][j];
            colSum[j] -= matrix[i][j];
            
            if (rowSum[i] == 0) ++i;
            else ++j;
        }
        
        return matrix;
    }
};