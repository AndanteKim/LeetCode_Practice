class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> belowRow = triangle.back();
        int n = triangle.size();
        
        for (int row = n - 2; row >= 0; --row){
            vector<int> currRow;
            for (int col = 0; col <= row; ++col){
                int smallest = min(belowRow[col], belowRow[col + 1]);
                currRow.push_back(smallest + triangle[row][col]);
            }
            belowRow = currRow;
        }
        
        return belowRow[0];
    }
};