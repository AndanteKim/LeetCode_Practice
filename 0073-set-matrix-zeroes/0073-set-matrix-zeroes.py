class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int R = matrix.size(), C = matrix[0].size();set<int> rows, cols;
        
        // Essentially, we mark the rows and columns that are to be made zero
        for (int i = 0; i < R; ++i){
            for (int j = 0; j < C; ++j)
                if (matrix[i][j] == 0){
                    rows.insert(i);
                    cols.insert(j);
                }
        }
        
        // Iterate over the array once again, and using rows and cols sets, update the elements
        for (int i = 0; i < R; ++i){
            for (int j = 0; j < C; ++j)
                if (rows.contains(i) || cols.contains(j))
                    matrix[i][j] = 0;
        }
    }
};