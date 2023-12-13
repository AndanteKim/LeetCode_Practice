class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int r = mat.size(), c = mat[0].size(), ans = 0;
        queue<pair<int, int>> q;
        
        for (int i = 0; i < r; ++i){
            for (int j = 0; j < c; ++j){
                if (mat[i][j])
                    q.push({i, j});
            }
        }
        
        while (!q.empty()){
            auto[row, col] = q.front();
            q.pop();
            
            bool satisfied = true;
            for (int i = 0; i < r; ++i){
                if (i != row && mat[i][col]){
                    satisfied = false;
                    break;
                }
            }
            
            if (!satisfied)
                continue;
            
            for (int i = 0; i < c; ++i){
                if (i != col && mat[row][i]){
                    satisfied = false;
                    break;
                }
            }
            
            if (satisfied)
                ++ans;
        }
        
        return ans;
    }
};