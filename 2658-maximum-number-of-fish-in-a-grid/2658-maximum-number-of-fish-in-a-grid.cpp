class Solution {
private:
    int m, n;
    const vector<pair<int, int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool isValid(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& visited){
        return 0 <= row && row < m && 0 <= col && col < n && grid[row][col] > 0 && !visited[row][col]; 
    }

    int bfs(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& visited){
        queue<pair<int, int>> q;
        q.push({row, col});
        int maxFishes = grid[row][col];
        visited[row][col] = true;

        while (!q.empty()){
            auto [currR, currC] = q.front(); q.pop();

            for (const auto& [dr, dc] : dirs){
                int newR = currR + dr, newC = currC + dc;
                if (isValid(newR, newC, grid, visited)){
                    q.push({newR, newC});
                    visited[newR][newC] = true;
                    maxFishes += grid[newR][newC];
                }
            }
        }

        return maxFishes;
    }


public:
    int findMaxFish(vector<vector<int>>& grid) {
        this -> m = grid.size(), this -> n = grid[0].size();
        int ans = 0;
        vector visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (grid[i][j] > 0)
                    ans = max(ans, bfs(i, j, grid, visited));
            }
        }

        return ans;
    }
};