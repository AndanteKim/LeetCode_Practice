class Solution {
private:
    int m, n;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int fireTime[302][302];
    int dis[302][302];
    
    int minTimeToReachBottomRight(int wasteTime, vector<vector<int>>& grid){
        queue<pair<int, int>> queue;
        queue.push({0, 0});
        
        for (int i = 0; i <= m; ++i) for (int j = 0; j <= n; ++j) dis[i][j] = int(1e9);
        
        dis[0][0] = wasteTime;
        
        while(!queue.empty()){
            auto [x, y] = queue.front();
            queue.pop();
            for (int i = 0; i < 4;++i){
                int nx = x + dx[i], ny = y + dy[i];
                
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] == 2) continue;
                    
                int newMin = min(dis[nx][ny], dis[x][y] + 1);
                if (nx == m - 1 && ny == n - 1 && newMin <= fireTime[nx][ny]) return newMin;
                
                if (newMin >= fireTime[nx][ny]) continue;
                
                if (dis[nx][ny] > dis[x][y] + 1) {
                    dis[nx][ny] = dis[x][y] + 1;
                    queue.push({nx, ny});
                }
            }
        }
        
        return 1e9 + 1;
    }
    
    int findMaxTime(vector<vector<int>>& grid){
        if (fireTime[m - 1][n - 1] == 1e9){
            return (minTimeToReachBottomRight(0, grid) >= 1e9)? -1 : 1e9;
        }
        
        int left = 0, right = m * n + 1, ans = -1;
        
        while (left <= right){
            int mid = ((left + right) >> 1);
            if (minTimeToReachBottomRight(mid, grid) <= fireTime[m - 1][n - 1]){
                ans = mid;
                left = mid + 1;
            }
            else right = mid - 1;
        }
        
        return (ans >= m * n + 1)? 1e9 : ans;
    }
    
public:
    int maximumMinutes(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        for (int i = 0; i <= m; ++i){
            for (int j = 0; j <= n; ++j) fireTime[i][j] = 1e9;
        }
        
        queue<pair<int, int>> queue;
        
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (grid[i][j] == 1){
                    queue.push({i, j});
                    fireTime[i][j] = 0;
                }
            }
        }
        
        while (!queue.empty()){
            auto [x, y] = queue.front();
            queue.pop();
            
            for (int i = 0; i < 4; ++i){
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] != 2){
                    if (fireTime[nx][ny] > fireTime[x][y] + 1){
                        fireTime[nx][ny] = fireTime[x][y] + 1;
                        queue.push({nx, ny});
                    }
                }
            }
        }
        
        int ans = findMaxTime(grid);
        return ans;
    }
};