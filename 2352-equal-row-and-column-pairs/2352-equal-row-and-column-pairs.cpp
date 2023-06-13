class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string, int> cols;
        int ans = 0;
        for (int i = 0; i < grid.size(); ++i){
            string key = "";
            for (int j = 0; j < grid[0].size(); ++j){
                key += to_string(grid[j][i]) + " ";
            }
            cols[key] += 1;
        }
        
        for (vector<int>& row : grid){
            string key = "";
            for (int col : row){
                key += to_string(col) + " ";
            }
            
            ans += cols[key];
        }
        
        return ans;
    }
};