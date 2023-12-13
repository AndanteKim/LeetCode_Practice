class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), ans = 0;
        
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (mat[i][j] == 0)
                    continue;
                
                bool good = true;
                for (int r = 0; r < m; ++r){
                    if (r != i && mat[r][j] == 1){
                        good = false;
                        break;
                    }
                }
                
                for (int c = 0; c < n; ++c){
                    if (c != j && mat[i][c] == 1){
                        good = false;
                        break;
                    }
                }
                
                if (good)
                    ++ans;
            }
        }
        
        return ans;
    }
};