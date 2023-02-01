class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> dic, dic2;
        vector<vector<int>> cols(grid[0].size(), vector<int>(grid.size(), 0));
        
        for (const vector<int>& row : grid) ++dic[row];
        for (int i = 0; i < grid.size(); ++i){
            for (int j = 0; j < grid[0].size(); ++j){
                cols[i][j] = grid[j][i];
            }
            ++dic2[cols[i]];
        }
        int ans = 0;
        for (const auto& [key, value] : dic) ans += dic[key] * dic2[key];
        return ans;
    }
};