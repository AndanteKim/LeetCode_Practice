class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        vector<vector<int>> columns(grid.size(), vector<int>(grid[0].size(), 0));
        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[0].size(); ++j)
                columns[i][j] = grid[j][i];
        int answer = 0;
        map<vector<int>, int> look_up_r, look_up_c;
        for (int i = 0; i < grid.size(); ++i) ++look_up_r[grid[i]];
        for (int i = 0; i < columns.size(); ++i) ++look_up_c[columns[i]];
        for (const auto &[key, value] : look_up_r){
            answer += look_up_r[key] * look_up_c[key];
        }
        return answer;
    }
};