class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size(), ans = INT_MAX;
        queue<vector<int>> queue;
        queue.push({entrance[0], entrance[1], 0});
        vector<vector<bool>> visited(m, vector<bool>(n));
        visited[entrance[0]][entrance[1]] = true;
        
        while (!queue.empty()){
            auto it = queue.front();
            int x = it[0], y = it[1], dist = it[2];
            queue.pop();
            
            if ((x == 0 || x == m - 1 || y == 0 || y == n - 1) && dist != 0)
                return dist;
            
            for (auto& [newX, newY] : vector<pair<int, int>>{{x + 1, y}, {x - 1, y}, {x, y + 1}, {x, y - 1}}){
                if (0 <= newX && newX < m && 0 <= newY && newY < n && maze[newX][newY] == '.' && !visited[newX][newY]){
                    visited[newX][newY] = true;
                    queue.push({newX, newY, dist + 1});
                }
            }
        }
        
        return -1;
    }
};