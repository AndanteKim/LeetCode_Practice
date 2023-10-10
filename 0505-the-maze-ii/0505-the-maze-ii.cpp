class Solution {
private:
    int m, n;
    bool isValid(int x, int y, vector<vector<int>>& maze){
        return 0 <= x && x < m && 0 <= y && y < n && maze[x][y] == 0;
    }
    
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        this -> m = maze.size(), this -> n = maze[0].size();
        queue<pair<int, int>> queue;
        queue.push(make_pair(start[0], start[1]));
        vector<vector<int>> distances(m, vector<int>(n, INT_MAX));
        distances[start[0]][start[1]] = 0;
        
        while (!queue.empty()){
            auto [x, y] = queue.front();
            queue.pop();
            
            for (auto& [dx, dy] : vector<pair<int, int>>{{1, 0}, {-1, 0}, {0, -1}, {0, 1}}){
                int newX = x + dx, newY = y + dy, dist = 0;
                
                while (isValid(newX, newY, maze)){
                    newX += dx;
                    newY += dy;
                    ++dist;
                }
                
                if (distances[x][y] + dist < distances[newX - dx][newY - dy]){
                    distances[newX - dx][newY - dy] = distances[x][y] + dist;
                    queue.push({newX - dx, newY - dy});
                }
            }
        }
        
        return distances[destination[0]][destination[1]] == INT_MAX? -1 : distances[destination[0]][destination[1]];
    }
};