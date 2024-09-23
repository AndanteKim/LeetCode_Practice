class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> prevRow = triangle[0];
        int m = triangle.size();
        
        for (int row = 1; row < m; ++row){
            vector<int> currRow;
            for (int col = 0; col <= row; ++col){
                int smallest = 1e5;
                if (col > 0) smallest = prevRow[col - 1];
                if (col < row) smallest = min(smallest, prevRow[col]);
                currRow.push_back(triangle[row][col] + smallest);
            }
            
            prevRow = currRow;
        }
        
        return *min_element(prevRow.begin(), prevRow.end());
    }
};