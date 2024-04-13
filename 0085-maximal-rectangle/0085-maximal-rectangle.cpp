class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxArea = 0, m = matrix.size(), n = matrix[0].size();
        
        // Initialize left and right as the leftmost and rightmost boundary possible for each
        vector<int> left(n, 0), right(n, n), height(n, 0);
        
        for (int i = 0; i < m; ++i){
            int currLeft = 0, currRight = n;
            
            // Update the height
            for (int j = 0; j < n; ++j){
                if (matrix[i][j] == '1') ++height[j];
                else
                    height[j] = 0;
            }
            
            // Update the left
            for (int j = 0; j < n; ++j){
                if (matrix[i][j] == '1') left[j] = max(left[j], currLeft);
                else{
                    left[j] = 0;
                    currLeft = j + 1;
                }
            }
            
            // Update the right
            for (int j = n - 1; j >= 0; --j){
                if (matrix[i][j] == '1') right[j] = min(right[j], currRight);
                else{
                    right[j] = n;
                    currRight = j;
                }
            }
            
            // Update the area
            for (int j = 0; j < n; ++j)
                maxArea = max(maxArea, height[j] * (right[j] - left[j]));
            
        }
        
        return maxArea;
    }
};