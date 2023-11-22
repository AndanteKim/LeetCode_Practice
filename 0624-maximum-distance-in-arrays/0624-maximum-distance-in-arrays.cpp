class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int ans = 0, n = arrays[0].size(), minVal = arrays[0][0], maxVal = arrays[0][n - 1];
        
        for (int i = 1; i < arrays.size(); ++i){
            n = arrays[i].size();
            ans = max(ans, max(abs(minVal - arrays[i][n - 1]), abs(maxVal - arrays[i][0])));
            minVal = min(minVal, arrays[i][0]);
            maxVal = max(maxVal, arrays[i][n - 1]);
        }
        
        return ans;
    }
};