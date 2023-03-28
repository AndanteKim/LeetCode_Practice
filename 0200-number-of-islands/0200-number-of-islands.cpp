class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        deque<pair<pair<int, int>, bool>> *dq = new deque<pair<pair<int, int>, bool>>;
        int rows = grid.size(), cols = grid[0].size(), ans = 0;
        vector<vector<bool>>visited(rows, vector<bool>(cols, false));
        for (int i = 0; i < rows; ++i){
            for (int j = 0; j < cols; ++j)
                if (grid[i][j] == '1') dq -> push_back({{i, j}, true});
        }
        
        while (!dq -> empty()){
            auto it = dq -> front();
            auto& [i,j] = it.first;
            bool is_origin = it.second;
            dq -> pop_front();
            if (!visited[i][j]){
                visited[i][j] = true;
                if (j > 0 && grid[i][j - 1] == '1') dq -> push_front({{i, j - 1}, false});
                if (i > 0 && grid[i - 1][j] == '1') dq -> push_front({{i - 1, j}, false});
                if (j < cols - 1 && grid[i][j + 1] == '1') dq -> push_front({{i, j + 1}, false});
                if (i < rows - 1 && grid[i + 1][j] == '1') dq -> push_front({{i + 1, j}, false});
                if (is_origin) ++ans;
            }
        }
        return ans;
    }
};