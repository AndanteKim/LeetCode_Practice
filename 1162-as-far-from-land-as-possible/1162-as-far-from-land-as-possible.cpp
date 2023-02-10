class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        
        int rows = grid.size(), cols = grid[0].size();
        
        const int MAX_DISTANCE = rows + cols + 1;
        
        vector<vector<int>> dist(rows, vector<int>(cols, MAX_DISTANCE));
        
        for (int i = 0; i < rows; ++i){
            for (int j = 0; j < cols; ++j){
                if (grid[i][j]) dist[i][j] = 0;
                else{
                    dist[i][j] = min(dist[i][j], min(i > 0? dist[i-1][j] + 1 : MAX_DISTANCE, j > 0? dist[i][j-1] + 1 : MAX_DISTANCE));
                }
            }
        }
        
        int ans = INT_MIN;
        for (int i = rows - 1; i >= 0; --i){
            for (int j = cols - 1; j >= 0; --j){
                dist[i][j] = min(dist[i][j], min(i < rows - 1? dist[i+1][j] + 1 : MAX_DISTANCE, j < cols - 1? dist[i][j+1] + 1 : MAX_DISTANCE));
                ans = max(ans, dist[i][j]);
            }
        }
        return ans == 0 || ans == MAX_DISTANCE? -1: ans;
    }
};