class Solution {
private:
    int rows, cols;
    bool isValid(int row, int col, vector<vector<int>>& maze){
        return 0 <= row && row < rows && 0 <= col && col < cols && maze[row][col] == 0;
    }
    
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        this -> rows = maze.size(), this -> cols = maze[0].size();
        
        if (maze[start[0]][start[1]] == 1) return false;
        
        queue<pair<int, int>> queue;
        queue.push(make_pair(start[0], start[1]));
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!queue.empty()){
            auto [x, y] = queue.front();
            queue.pop();
            
            if (x == destination[0] && y == destination[1]) return true;
            
            if (visited[x][y]) continue;
            
            visited[x][y] = true;
            for (auto& [dx, dy] : directions){
                int newX = x, newY = y;
                
                while (isValid(newX + dx, newY + dy, maze)){
                    newX += dx;
                    newY += dy;
                }
                
                queue.push(make_pair(newX, newY));
            }
        }
        
        return false;
    }
};