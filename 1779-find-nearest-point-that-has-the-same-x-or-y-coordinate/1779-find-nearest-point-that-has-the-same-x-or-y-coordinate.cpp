class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int curr = INT_MAX, ans = -1, i = 0;
        for (const auto &point : points){
            if (point[0] == x || point[1] == y){
                if (curr > abs(point[0] - x) + abs(point[1] - y)){
                    curr = abs(point[0] - x) + abs(point[1] - y);
                    ans = i;
                }
            }
            ++i;
        }
        return ans;
    }
};