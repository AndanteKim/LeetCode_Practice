class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0, j = n - 1;
        for (const auto& row : grid) {
            while (j >= 0 && row[j] < 0) --j;
            ans += n - (j + 1);
        }

        return ans;
    }
};