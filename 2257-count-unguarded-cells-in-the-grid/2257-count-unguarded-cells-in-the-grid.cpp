class Solution {
private:
    const int UNGUARDED = 0, GUARDED = 1, GUARD = 2, WALL = 3;
    int m, n;
    
    void dfs(int row, int col, vector<vector<int>>& grid, char direction){
        // Base case
        if (row < 0 || row >= m || col < 0 || col >= n || grid[row][col] == GUARD || grid[row][col] == WALL)
            return;
        
        // Mark cell as guarded
        grid[row][col] = GUARDED;
        
        if (direction == 'U')
            dfs(row - 1, col, grid, direction);
        else if (direction == 'D')
            dfs(row + 1, col, grid, direction);
        else if (direction == 'L')
            dfs(row, col - 1, grid, direction);
        else
            dfs(row, col + 1, grid, direction);
    }
        
    
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        this -> m = m, this -> n = n;
        vector<vector<int>> grid(m, vector<int>(n));
        
        // Mark the guards' position
        for (const auto& guard: guards)
            grid[guard[0]][guard[1]] = GUARD;
        
        // Mark the walls' position
        for (const auto& wall : walls)
            grid[wall[0]][wall[1]] = WALL;
        
        // Mark cells as guarded by traversing from each guard
        for (const auto& guard : guards){
            dfs(guard[0] - 1, guard[1], grid, 'U');  // Up
            dfs(guard[0] + 1, guard[1], grid, 'D');  // Down
            dfs(guard[0], guard[1] - 1, grid, 'L');  // Left
            dfs(guard[0], guard[1] + 1, grid, 'R');  // Right
        }
        
        // Count unguarded cells
        int count = 0;
        for (const auto& row : grid){
            for (const int cell : row)
                if (cell == UNGUARDED) ++count;
        }
        
        return count;
    }
};