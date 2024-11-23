class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size(), n = box[0].size();
        vector ans(n, vector<char>(m));
        
        // Create the transpose of the input grid in 'ans'
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                ans[j][i] = box[i][j];
            }
        }
        
        // Reverse each row in the transpose grid to complete the 90° rotation
        for (int i = 0; i < n; ++i)
            reverse(begin(ans[i]), end(ans[i]));
        
        // Apply gravity to let stones fall to the lowest possible empty cell in each column
        for (int j = 0; j < m; ++j){
            int lowestRowWithEmptyCell = n - 1;
            
            // Process each cell in column 'j' from bottom to top
            for (int i = n - 1; i >= 0; --i){
                // Found a stone - let it fall to the lowest empty cell
                if (ans[i][j] == '#')
                    swap(ans[i][j], ans[lowestRowWithEmptyCell--][j]);
                
                // Found an obstacle - reset 'lowestRowWithEmptyCell' to the row directly above it
                if (ans[i][j] == '*')
                    lowestRowWithEmptyCell = i - 1;
            }
        }
        
        return ans;
    }
};