class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        vector<vector<int>> r = restrictions;
        r.push_back({1, 0});
        sort(r.begin(), r.end());

        if (r.back()[0] != n) r.push_back({n, n - 1});

        int ans = 0, m = r.size();

        // Pass restrictions from left to right
        for (int i = 1; i < m; ++i)
            r[i][1] = min(r[i][1], r[i - 1][1] + (r[i][0] - r[i - 1][0]));

        // Pass restrictions from right to left
        for (int i = m - 2; i > 0; --i)
            r[i][1] = min(r[i][1], r[i + 1][1] + (r[i + 1][0] - r[i][0]));

        for (int i = 0; i < m - 1; ++i) {
            int best = ((r[i + 1][0] - r[i][0]) + r[i][1] + r[i + 1][1]) >> 1;
            ans = max(ans, best);
        }

        return ans;
    }
};