class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), ans = 0;
        
        for (int row = 0; row < m; ++row){
            for (int col = 0; col < n; ++col){
                if (matrix[row][col] && row > 0)
                    matrix[row][col] += matrix[row - 1][col];
            }
            vector<int> currRow(matrix[row].begin(), matrix[row].end());
            sort(currRow.begin(), currRow.end(), [](int a, int b) {return a > b;});
            
            for (int i = 0; i < n; ++i)
                ans = max(ans, currRow[i] * (i + 1));
        }
        
        return ans;
    }
};