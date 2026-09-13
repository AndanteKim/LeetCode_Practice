class Solution {
protected:
    int m;
    vector<pair<int, int>> nonZeroCnt(vector<vector<int>>& M) {
        vector<pair<int, int>> flatten;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                if (M[i][j]) flatten.push_back({i, j});
            }
        }

        return flatten;
    }

public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        this -> m = img1.size();
        unordered_map<string, int> transCnt;
        vector<pair<int, int>> A = nonZeroCnt(img1), B = nonZeroCnt(img2);
        int ans = 0;

        for (const auto& [x1, y1] : A) {
            for (const auto& [x2, y2] : B) {
                int diffX = x2 - x1, diffY = y2 - y1;
                string diff = to_string(diffX) + ", " + to_string(diffY);
                ++transCnt[diff];
                ans = max(ans, transCnt[diff]);
            }
        }

        return ans;
    }
};