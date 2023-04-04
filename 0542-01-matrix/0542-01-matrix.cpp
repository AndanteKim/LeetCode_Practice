class Solution {
    int rows, cols;
    vector<pair<int, int>> directions{{0,1}, {1, 0}, {0, -1}, {-1, 0}};
    bool valid(int x, int y, vector<vector<int>>& mat){
        return (x >= 0 && x < rows) && (y >= 0 && y < cols) && mat[x][y];
    }
    
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        rows = mat.size(), cols = mat[0].size();
        queue<vector<int>> *q = new queue<vector<int>>;
        vector<vector<bool>> seen(rows, vector<bool>(cols, false));
        for (int row = 0; row < rows; ++row){
            for (int col = 0; col < cols; ++col)
                if (!mat[row][col]){
                    seen[row][col] = true;
                    q -> push({row, col, 1});
                }
        }
        
        while (!q -> empty()){
            auto it = q -> front();
            q -> pop();
            int x = it[0], y = it[1], dist = it[2];
            
            for (auto& [dx, dy] : directions){
                int next_row = x + dx, next_col = y + dy;
                if (valid(next_row, next_col, mat) && !seen[next_row][next_col]){
                    seen[next_row][next_col] = true;
                    q -> push({next_row, next_col, dist + 1});
                    mat[next_row][next_col] = dist;
                }
            }
        }
        return mat;
    }
};