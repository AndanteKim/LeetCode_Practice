class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector prefix(m + 1, vector(n + 1, vector<int>(2)));
        int ans = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 'X') {
                    prefix[i + 1][j + 1][0] = prefix[i + 1][j][0] + prefix[i][j + 1][0] - prefix[i][j][0] + 1;
                    prefix[i + 1][j + 1][1] = 1;
                }
                else if (grid[i][j] == 'Y') {
                    prefix[i + 1][j + 1][0] = prefix[i + 1][j][0] + prefix[i][j + 1][0] - prefix[i][j][0] - 1;
                    prefix[i + 1][j + 1][1] = prefix[i + 1][j][1] | prefix[i][j + 1][1];
                }
                else {
                    prefix[i + 1][j + 1][0] = prefix[i + 1][j][0] + prefix[i][j + 1][0] - prefix[i][j][0];
                    prefix[i + 1][j + 1][1] = prefix[i + 1][j][1] | prefix[i][j + 1][1];
                }

                if (prefix[i + 1][j + 1][0] == 0 && prefix[i + 1][j + 1][1] == 1) ++ans;
            }
        }

        return ans;
    }
};