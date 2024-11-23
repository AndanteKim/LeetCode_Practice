class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size(), n = box[0].size();
        vector ans(n, vector<char>(m, '.'));
        
        // Apply gravity to let stones fall to the lowest possible empty cell in each column
        for (int i = 0; i < m; ++i){
            int lowestRowWithEmptyCell = n - 1;
            // Process each cell in row 'i' in reversed order
            for (int j = n - 1; j >= 0; --j){
                // Found a stone - let it fall to the lowest empty cell
                if (box[i][j] == '#'){
                    // Place it in the correct position in the rotated grid 
                    ans[lowestRowWithEmptyCell--][m - 1 - i] = '#';
                }
                
                // Found an obstacle - reste 'lowestRowWithEmptyCell' to the row directly above it
                if (box[i][j] == '*'){
                    // Place the obstacle in the correct position in the rotated grid
                    ans[j][m - 1 - i] = '*';
                    lowestRowWithEmptyCell = j - 1;
                }
            }
        }
        
        return ans;
    }
};