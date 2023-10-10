class Solution {
private:
    int m, n;
    pair<int, int> minDistance(vector<vector<int>>& distances, vector<vector<bool>>& visited){
        int minVal = INT_MAX, x = -1, y = -1;
        
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (!visited[i][j] && distances[i][j] < minVal){
                    minVal = distances[i][j];
                    x = i, y = j;
                }
            }
        }
        return make_pair(x, y);
    }
    
    void dijkstra(vector<vector<int>>& maze, vector<vector<int>>& distances, vector<vector<bool>>& visited){
        
        while(true){
            auto [x, y] = minDistance(distances, visited);
            
            if (x < 0)
                break;
            visited[x][y] = true;
            
            for (auto& [dx, dy] : vector<pair<int, int>> {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}){
                int newX = x + dx, newY = y + dy, dist = 0;
                
                while (0 <= newX && newX < m && 0 <= newY && newY < n && maze[newX][newY] == 0){
                    newX += dx;
                    newY += dy;
                    ++dist;
                }
                if (distances[x][y] + dist < distances[newX - dx][newY - dy]){
                    distances[newX - dx][newY - dy] = distances[x][y] + dist;
                }
            }
        }
    }
    
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        this -> m = maze.size(), this -> n = maze[0].size();
        vector distances(m, vector<int>(n, INT_MAX));
        vector visited(m, vector<bool>(n));
        distances[start[0]][start[1]] = 0;
        
        dijkstra(maze, distances, visited);
        return distances[destination[0]][destination[1]] == INT_MAX? -1 : distances[destination[0]][destination[1]];
    }
};