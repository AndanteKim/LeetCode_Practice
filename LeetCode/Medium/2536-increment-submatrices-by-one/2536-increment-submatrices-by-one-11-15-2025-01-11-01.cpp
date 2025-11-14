class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector diff(n + 1, vector<int>(n + 1));

        for (const auto& query : queries) {
            int r1 = query[0], c1 = query[1], r2 = query[2], c2 = query[3];
            ++diff[r1][c1];
            --diff[r2 + 1][c1];
            --diff[r1][c2 + 1];
            ++diff[r2 + 1][c2 + 1];
        }

        vector ans(n, vector<int>(n));
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int x1 = (i == 0)? 0 : ans[i - 1][j];
                int x2 = (j == 0)? 0 : ans[i][j - 1];
                int x3 = (i == 0 || j == 0)? 0 : ans[i - 1][j - 1];
                ans[i][j] = diff[i][j] + x1 + x2 - x3;
            }
        }

        return ans;
    }
};