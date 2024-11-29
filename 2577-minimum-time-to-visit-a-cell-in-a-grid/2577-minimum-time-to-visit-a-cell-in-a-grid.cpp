class Solution {
private:
    int m, n;
    
    // Checks if given cell coordinates are valid and unvisited
    bool isValid(int row, int col, vector<vector<int>>& visited){
        return 0 <= row && row < m && 0 <= col && col < n && visited[row][col] == std::numeric_limits<int>::max();
    }
    
public:
    int minimumTime(vector<vector<int>>& grid) {
        this -> m = grid.size(), this -> n = grid[0].size();
        vector visited(m, vector<int>(n, std::numeric_limits<int>::max()));
        // Possible movements: down, up, right, left
        vector<pair<int, int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        // If both initial moves require more than 1 second, impossible to proceed
        if (grid[0][1] > 1 && grid[1][0] > 1) return -1;
        
        // Priority queue stores (time, row, col)
        // Ordered by minimum time to reach each cell
        priority_queue<tuple<int, int, int>,  vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.push({grid[0][0], 0, 0});
        
        while (!pq.empty()){
            auto [time, row, col] = pq.top(); pq.pop();
            
            if (row == m - 1 && col == n - 1) return time;
            
            if (visited[row][col] != std::numeric_limits<int>::max()) continue;
            
            visited[row][col] = time;
            
            for (auto& [dr, dc] : directions){
                int nextRow = row + dr, nextCol = col + dc;
                
                if (!isValid(nextRow, nextCol, visited))
                    continue;
                
                // Calculate the wait time needed to move to next cell
                int waitTime = (grid[nextRow][nextCol] - time) % 2 == 0? 1 : 0;
                int nextTime = max(grid[nextRow][nextCol] + waitTime, time + 1);
                pq.push({nextTime, nextRow, nextCol});
            }
        }
        
        return -1;
    }
};