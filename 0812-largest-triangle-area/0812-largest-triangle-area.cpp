class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double ans = 0.0;

        for (int i = 0; i < n; ++i){
            pair<int, int> p = {points[i][0], points[i][1]};
            for (int j = i + 1; j < n; ++j){
                pair<int, int> q = {points[j][0], points[j][1]};
                for (int k = j + 1; k < n; ++k){
                    pair<int, int> r = {points[k][0], points[k][1]};
                    ans = max(ans, 0.5 * (abs((p.first * q.second + q.first * r.second + r.first * p.second) - (p.second * q.first + q.second * r.first + r.second * p.first))));
                }
            }
        }

        return ans;
    }
};