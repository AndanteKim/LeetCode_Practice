class Solution {
private:
    int m, n;
    void dijkstra(vector<vector<int>>& maze, vector<int>& start, vector<vector<int>>& distances){
        auto comp = [](vector<int> &a, vector<int> &b){
            return a[2] - b[2];
        };
        
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq;
        pq.push({start[0], start[1], 0});
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int x = it[0], y = it[1], curr = it[2];
            if (distances[x][y] < curr) continue;
            
            for (auto& [dx, dy] : vector<pair<int, int>>{{1, 0}, {-1, 0}, {0, -1}, {0, 1}}){
                int newX = x + dx, newY = y + dy, dist = 0;
                
                while (0 <= newX && newX < m && 0 <= newY && newY < n && maze[newX][newY] == 0){
                    newX += dx;
                    newY += dy;
                    ++dist;
                }
                
                if (distances[x][y] + dist < distances[newX - dx][newY - dy]){
                    distances[newX - dx][newY - dy] = distances[x][y] + dist;
                    pq.push(vector<int>{newX - dx, newY - dy, dist});
                }
            }
        }
    }
    
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        this -> m = maze.size(), this -> n = maze[0].size();
        vector distances(m, vector<int>(n, INT_MAX));
        distances[start[0]][start[1]] = 0;
        dijkstra(maze, start, distances);
        return distances[destination[0]][destination[1]] == INT_MAX? -1 : distances[destination[0]][destination[1]];
    }
};