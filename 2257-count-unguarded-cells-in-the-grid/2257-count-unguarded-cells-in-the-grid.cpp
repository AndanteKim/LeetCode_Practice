class Solution {
private:
    int m, n;
    const int UNGUARDED = 0, GUARDED = 1, GUARD = 2, WALL = 3;
    
    void markGuarded(int row, int col, vector<vector<int>>& grid){
        // Traverse upwards
        for (int r = row - 1; r >= 0; --r){
            if (grid[r][col] == WALL || grid[r][col] == GUARD)
                break;
            grid[r][col] = GUARDED;
        }
        
        // Traverse downwards
        for (int r = row + 1; r < m; ++r){
            if (grid[r][col] == WALL || grid[r][col] == GUARD)
                break;
            grid[r][col] = GUARDED;
        }
        
        // Traverse leftwards
        for (int c = col - 1; c >= 0; --c){
            if (grid[row][c] == WALL || grid[row][c] == GUARD)
                break;
            grid[row][c] = GUARDED;
        }
        
        // Traverse rightwards
        for (int c = col + 1; c < n; ++c){
            if (grid[row][c] == WALL || grid[row][c] == GUARD)
                break;
            grid[row][c] = GUARDED;
        }
    }
    
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        this -> m = m, this -> n = n;
        vector<vector<int>> grid(m, vector<int>(n));
        
        // Mark guards' positions
        for (const auto& guard : guards){
            grid[guard[0]][guard[1]] = GUARD;
        }
        
        // Mark walls' positions
        for (const auto& wall : walls){
            grid[wall[0]][wall[1]] = WALL;
        }   
        
        // Mark cells as guarded by traversing from each guard
        for (const auto& guard : guards){
            markGuarded(guard[0], guard[1], grid);
        }
        
        // Count unguarded cells
        int count = 0;
        for (const auto& row : grid){
            for (int cell : row){
                if (cell == UNGUARDED) ++count;
            }
        }
        
        return count;
    }
};