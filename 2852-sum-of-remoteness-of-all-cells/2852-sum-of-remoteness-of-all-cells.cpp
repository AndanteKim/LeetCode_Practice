class Solution {
private:
    int n;
    // Direction array for moving up, down, left, right
    const vector<pair<int, int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    // Checks if cell (row, col) is within grid bounds and not blocked / visited
    bool isValid(int row, int col, vector<vector<int>>& grid){
        return 0 <= row && row < n && 0 <= col && col < n && grid[row][col] > 0;
    }

    // BFS to find sum and count of all cells reachable from (row, col)
    long long bfs(int row, int col, long long total, vector<vector<int>>& grid){
        // Sum of values in current component
        // Number of cells in component and Mark as visited
        long long compSum = grid[row][col], compCount = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        grid[row][col] = -1;

        while (!q.empty()){
            auto [currRow, currCol] = q.front(); q.pop();

            // Explore all 4 directions
            for (const auto&[dr, dc] : dirs){
                int newRow = currRow + dr, newCol = currCol + dc;
                if (isValid(newRow, newCol, grid)){
                    q.push({newRow, newCol});
                    compSum += grid[newRow][newCol];
                    ++compCount;
                    grid[newRow][newCol] = -1;
                }
            }
        }

        // Return remoteness value for this component
        return (total - compSum) * compCount;
    }

public:
    long long sumRemoteness(vector<vector<int>>& grid) {
        this -> n = grid.size();
        // Calculate total sum of all non-blocked cells
        long long total = 0;

        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                if (grid[i][j] != -1)
                    total += grid[i][j];
            }
        }

        // Calculate remoteness for each non-blocked cell
        long long ans = 0;
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                if (grid[i][j] != -1)
                    ans += bfs(i, j, total, grid);
            }
        }

        return ans;
    } 
};