class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
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