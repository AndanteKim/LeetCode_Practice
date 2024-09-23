class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        
        for (int row = 1; row < m; ++row){
            for (int col = 0; col <= row; ++col){
                int smallest = 1e5;
                if (col > 0) smallest = triangle[row - 1][col - 1];
                
                if (col < row) smallest = min(smallest, triangle[row - 1][col]);
            
                triangle[row][col] += smallest;
            }
        }
        
        return *min_element(triangle.back().begin(), triangle.back().end());
    }
};