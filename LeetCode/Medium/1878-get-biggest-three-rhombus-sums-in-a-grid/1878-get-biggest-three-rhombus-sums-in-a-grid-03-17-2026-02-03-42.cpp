class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        set<int> st;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // size 0 rhombus
                st.insert(grid[i][j]);

                for (int k = 1; ;++k) {
                    int r = i + 2 * k;
                    int left = j - k, right = j + k;

                    if (r >= m || left < 0 || right >= n) break;

                    int sum = 0, x = i, y = j;

                    // Top -> right
                    for (int t = 0; t < k; ++t) sum += grid[x + t][y + t];

                    // Right -> bottom
                    for (int t = 0; t < k; ++t) sum += grid[x + k + t][y + k - t];

                    // Bottom -> left
                    for (int t = 0; t < k; ++t) sum += grid[x + 2 * k - t][y - t];

                    // Left -> top
                    for (int t = 0; t < k; ++t) sum += grid[x + k - t][y - k + t];

                    st.insert(sum);
                }
            }
        }

        vector<int> ans;
        for (auto it = st.rbegin(); it != st.rend() && ans.size() < 3; ++it) ans.push_back(*it);
        return ans;
    }
};