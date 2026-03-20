class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector ans(m - k + 1, vector<int>(n - k + 1, 0));

        for (int i = 0; i <= m - k; ++i) {
            for (int j = 0; j <= n - k; ++j) {
                vector<int> elements;
                for (int r = i; r < i + k; ++r) {
                    for (int c = j; c < j + k; ++c) {
                        elements.push_back(grid[r][c]);
                    }
                }
                
                sort(elements.begin(), elements.end());
                int minDiff = std::numeric_limits<int>::max();
                for (int i = 0; i < elements.size() - 1; ++i) {
                    if (elements[i] == elements[i + 1]) continue;
                    minDiff = min(minDiff, abs(elements[i + 1] - elements[i]));
                }
                cout << minDiff << endl;
                if (minDiff != std::numeric_limits<int>::max()) ans[i][j] = minDiff;
            }
        }

        return ans;
    }
};