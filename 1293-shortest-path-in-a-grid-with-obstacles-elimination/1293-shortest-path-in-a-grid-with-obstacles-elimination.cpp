class Solution {
    int m, n;
    vector<pair<int, int>> directions{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    bool valid(int nextRow, int nextCol){
        return (0 <= nextRow && nextRow < m) && (0 <= nextCol && nextCol < n);
    }
    
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        m = grid.size(), n = grid[0].size();
        queue<vector<int>> *q = new queue<vector<int>>;
        vector<vector<int>> seen(m, vector<int>(n, -1));
        q -> push({0, 0, k, 0});
        
        while (!q -> empty()){
            vector<int> curr = q -> front();
            q -> pop();
            int row = curr[0], col = curr[1], remain = curr[2], steps = curr[3];
            if (row == m - 1 && col == n - 1) return steps;
            
            if (grid[row][col]){
                if (!remain) continue;
                else --remain;
            }
        
            if (seen[row][col] >= remain) continue;
            seen[row][col] = remain;
        
            for (auto& [dr, dc] : directions){
                int nextRow = row + dr, nextCol = col + dc;
                if (valid(nextRow, nextCol)) q -> push({nextRow, nextCol, remain, steps + 1});
            }
        }
        return -1;
    }
};