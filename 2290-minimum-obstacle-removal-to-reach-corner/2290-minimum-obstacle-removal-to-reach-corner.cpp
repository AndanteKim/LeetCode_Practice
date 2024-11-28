class Solution {
private:
    int m, n;
    
    bool isValid(int x, int y){
        return 0 <= x && x < m && 0 <= y && y < n;
    }
    
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        this -> m = grid.size(), this -> n = grid[0].size();
        
        vector visited(m, vector<int>(n, std::numeric_limits<int>::max()));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.push({0, 0, 0});
        
        while (!pq.empty()){
            auto [minRemove, i, j] = pq.top(); pq.pop();
            if (minRemove >= visited[i][j]) continue;
            
            if (i == m - 1 && j == n - 1) return minRemove;
            
            visited[i][j] = minRemove;
            for (auto& [di, dj] : vector<pair<int, int>> {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}){
                int newI = i + di, newJ = j + dj;
                if (isValid(newI, newJ))
                    pq.push({grid[newI][newJ] + minRemove, newI, newJ});
                
            }
        }
        
        return -1;
    }
};