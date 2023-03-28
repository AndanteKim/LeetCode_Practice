class Solution {
    vector<pair<int, int>> directions{{0,1}, {1,0}, {0, -1}, {-1, 0}};
    int m, n;
    vector<vector<char>> grid;
    set<pair<int, int>> seen;
    bool valid(int row, int col){
        return (0 <= row && row < m) && (0 <= col && col < n) && this -> grid[row][col] == '1'; 
    }
    
    void dfs(int row, int col){
        for (auto& [dx, dy] : directions){
            int next_row = row + dy, next_col = col + dx;
            if (valid(next_row, next_col) && seen.find({next_row, next_col}) == seen.end()){
                seen.insert({next_row, next_col});
                dfs(next_row, next_col);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();
        this -> grid = grid;
        int ans = 0;
        for (int row = 0; row < m; ++row){
            for (int col = 0; col < n; ++col){
                if (grid[row][col] == '1' && seen.find({row, col}) == seen.end()){
                    ++ans;
                    seen.insert({row, col});
                    dfs(row, col);
                }
            }
        }
        
        return ans;
    }
};