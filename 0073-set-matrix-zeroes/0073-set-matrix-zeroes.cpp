class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bitset<201> mask;
        int m = matrix.size(), n = matrix[0].size();
        
        for (int i = 0; i < m; ++i){
            bool zero = false;
            for (int j = 0; j < n; ++j)
                if (!matrix[i][j]){
                    mask.set(j);
                    zero = true;
                }
            
            if (zero){
                memset(&matrix[i][0], '\0', sizeof(int) * n);
            }
        }
        
        for (int j = 0; j < n; ++j){
            if (mask.test(j)){
                for (int i = 0; i < m; ++i) matrix[i][j] = 0;
            }
        }
        
    }
};