class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int rMinMax = INT_MIN;
        
        for (int i = 0; i < m; ++i){
            int rMin = *min_element(matrix[i].begin(), matrix[i].end());
            rMinMax = max(rMin, rMinMax);
        }
        
        int cMaxMin = INT_MAX;
        for (int i = 0; i < n; ++i){
            int cMax = INT_MIN;
            for (int j = 0; j < m; ++j)
                cMax = max(cMax, matrix[j][i]);
            
            cMaxMin = min(cMax, cMaxMin);
        }
        
        return (rMinMax == cMaxMin)? vector<int>{rMinMax} : vector<int>{};
    }
};