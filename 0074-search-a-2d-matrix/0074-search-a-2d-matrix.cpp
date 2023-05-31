class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row_left = 0, row_right = matrix.size();
        
        while (row_left < row_right){
            int row_mid = row_left + (row_right - row_left) / 2;
            
            if (matrix[row_mid][0] <= target && target <= matrix[row_mid].back()){
                int col_left = 0, col_right = matrix[0].size();
                while (col_left < col_right){
                    int col_mid = col_left + (col_right - col_left) / 2;
                    if (target == matrix[row_mid][col_mid]) return true;
                    if (target < matrix[row_mid][col_mid]) col_right = col_mid;
                    else col_left = col_mid + 1;
                }
            }
            if (target < matrix[row_mid][0]) row_right = row_mid;
            else row_left = row_mid + 1;
        }
        
        return false;
    }
};