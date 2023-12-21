class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        set<int> widthPoints;
        int ans = 0, current = 1'000'000'000;
        
        for (vector<int>& point:points){
            if (widthPoints.count(point[0]))
                continue;
            
            widthPoints.insert(point[0]);
        }
        
        
        for (int point:widthPoints){
            ans = max(ans, point - current);
            current = point;
        }
        
        return ans;
    }
};