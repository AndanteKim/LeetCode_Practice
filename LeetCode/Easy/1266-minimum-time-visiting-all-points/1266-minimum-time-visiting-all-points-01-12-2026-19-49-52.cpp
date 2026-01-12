class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0, m = points.size();

        for (int i = 1; i < m; ++i) {
            int currX = points[i - 1][0], currY = points[i - 1][1];
            int nextX = points[i][0], nextY = points[i][1];
            ans += max(abs(currX - nextX), abs(currY - nextY));
        }

        return ans;
    }
};