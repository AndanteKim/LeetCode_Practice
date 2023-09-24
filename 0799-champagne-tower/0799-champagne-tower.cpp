class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> ans;
        for (int i = 1; i <= 101; ++i)
            ans.push_back(vector<double>(i, 0.0));
        
        ans[0][0] = poured;
        for (int r = 0; r <= query_row; ++r){
            for (int c = 0; c <= r; ++c){
                double quotient = (ans[r][c] - 1.0) / 2.0;
                if (quotient > 0){
                    ans[r + 1][c] += quotient;
                    ans[r + 1][c + 1] += quotient;
                }
            }
        }
        
        return min(1.0, ans[query_row][query_glass]);
    }
};