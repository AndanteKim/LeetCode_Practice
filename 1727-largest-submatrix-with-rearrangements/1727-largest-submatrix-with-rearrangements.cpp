class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), ans = 0;
        vector<int> prevRow(n);
        
        for (int row = 0; row < m; ++row){
            vector<int> currRow(matrix[row].begin(), matrix[row].end());
            for (int col = 0; col < n; ++col){
                if (matrix[row][col])
                    currRow[col] += prevRow[col];
                
            }
            vector<int> sortedRow(currRow.begin(), currRow.end());
            sort(sortedRow.begin(), sortedRow.end(), [](int a, int b){return a > b;});
            for (int i = 0; i < n; ++i){
                ans = max(ans, sortedRow[i] * (i + 1));
            }
            
            prevRow = currRow;
        }
        
        return ans;
    }
};