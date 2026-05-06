class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size(), n = boxGrid[0].size();
        vector ans(n, vector<char>(m, '.'));

        for (int r = 0; r < m; ++r) {
            int p = n - 1;

            for (int c = n - 1; c >= 0; --c) {
                if (boxGrid[r][c] == '*') {
                    ans[c][m - 1 - r] = '*';
                    p = c - 1;
                }
                else if (boxGrid[r][c] == '#') {
                    ans[p--][m - 1 - r] = '#';
                }
            }
        }

        return ans;
    }
};