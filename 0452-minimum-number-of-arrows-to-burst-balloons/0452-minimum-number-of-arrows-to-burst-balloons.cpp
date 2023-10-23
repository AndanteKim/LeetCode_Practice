class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b){return a[1] < b[1];});
        int ans = 0; 
        long currPoint = LONG_MIN;
        
        for (vector<int>& point : points){
            if (currPoint < point[0]){
                ++ans;
                currPoint = point[1];
            }
        }
        
        return ans;
    }
};