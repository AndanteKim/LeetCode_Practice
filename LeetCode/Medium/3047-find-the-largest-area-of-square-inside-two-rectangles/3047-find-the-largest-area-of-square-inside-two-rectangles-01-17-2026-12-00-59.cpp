class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        long long ans = 0;
        int m = bottomLeft.size();

        for (int i = 0; i < m - 1; ++i) {
            const int b1X = bottomLeft[i][0], b1Y = bottomLeft[i][1];
            const int t1X = topRight[i][0], t1Y = topRight[i][1];
            for (int j = i + 1; j < m; ++j) {
                const int b2X = bottomLeft[j][0], b2Y = bottomLeft[j][1];
                const int t2X = topRight[j][0], t2Y = topRight[j][1];

                const int bMaxX = max(b1X, b2X), tMinX = min(t1X, t2X);
                const int bMaxY = max(b1Y, b2Y), tMinY = min(t1Y, t2Y);
                
                const int length = max(0, min((tMinX - bMaxX), (tMinY - bMaxY)));
                ans = max(ans, 1LL * length * length);
            }
        }

        return ans;
    }
};