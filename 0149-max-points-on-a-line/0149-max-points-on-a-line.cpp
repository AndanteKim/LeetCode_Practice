class Solution {
private:
    double calculateSlope(vector<int>& p1, vector<int>& p2){
        int x1 = p1[0], x2 = p2[0];
        int y1 = p1[1], y2 = p2[1];
        
        if (x1 == x2) return DBL_MAX;
        if (y1 == y2) return 0;
        
        return (double) (y2 - y1) / (x2 - x1);
    }
    
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        if (n == 1)
            return 1;
        
        int ans = 0;
        
        for (int i = 0; i < n; ++i){
            unordered_map<double, int> count;
            for (int j = i + 1; j < n; ++j){
                double slope = calculateSlope(points[i], points[j]);
                ++count[slope];
                ans = max(ans, count[slope]);
            }
        }
        
        // Since points[i] also lies on the line
        return ans + 1;
    }
};