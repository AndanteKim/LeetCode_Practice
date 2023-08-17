class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        queue<vector<int>> queue;
        vector<vector<bool>> visited(m, vector<bool>(n));
        vector<vector<int>> ans(m, vector<int>(n));
        
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (!mat[i][j]){
                    queue.push({i, j, 1});
                    visited[i][j] = true;
                }
            }
        }
        
        while (!queue.empty()){
            auto it = queue.front();
            queue.pop();
            int x = it[0], y = it[1], dist = it[2];
            
            for (auto &[newX, newY] : vector<pair<int, int>>{{x + 1, y}, {x - 1, y}, {x, y - 1}, {x, y + 1}}){
                if (0 <= newX && newX < m && 0 <= newY && newY < n && !visited[newX][newY]){
                    visited[newX][newY] = true;
                    queue.push({newX, newY, dist + 1});
                    ans[newX][newY] = dist;
                }
            }
        }
        
        return ans;
    }
};