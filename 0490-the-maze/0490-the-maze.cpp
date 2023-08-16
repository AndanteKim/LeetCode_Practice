class Solution {
private:
    int m, n;
    bool dfs(vector<vector<int>>& maze, vector<int> curr, vector<int>& destination, vector<vector<bool>>& visited){
        if (visited[curr[0]][curr[1]]) return false;
        if (curr[0] == destination[0] && curr[1] == destination[1]) return true;
        
        int dirX[4] = {-1, 0, 1, 0}, dirY[4] = {0, 1, 0, -1};
        visited[curr[0]][curr[1]] = true;
        for (int i = 0; i < 4; ++i){
            int r = curr[0], c = curr[1];
            
            while (0 <= r && r < m && 0 <= c && c < n && maze[r][c] == 0){
                r += dirX[i];
                c += dirY[i];
            }
            
            if (dfs(maze, {r - dirX[i], c - dirY[i]}, destination, visited)) return true;
        }
        
        return false;
    }
    
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        this -> m = maze.size(), this -> n = maze[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        return dfs(maze, start, destination, visited);
    }
};