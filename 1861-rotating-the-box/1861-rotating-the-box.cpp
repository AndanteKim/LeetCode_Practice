class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size(), n = box[0].size();
        
        vector<vector<char>> rotatedBox(n, vector<char>(m));
        
        // Create the transpose of the input grid in 'rotatedBox'
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j)
                rotatedBox[i][j] = box[j][i];
        }
        
        // Reverse each row in the transpose grid to complete the 90° rotation
        for (int i = 0; i < n; ++i) reverse(rotatedBox[i].begin(), rotatedBox[i].end());
        
        // Apply gravity to let stones fall to the lowest possible empty cell in
        // each column
        for (int j = 0; j < m; ++j){
            
            // Process each cell in column 'j' from bottom to top
            for (int i = n - 1; i >= 0; --i){
                if (rotatedBox[i][j] == '.'){   // Found an empty cell; check if a stone can fall into it
                    int nextRowWithStone = -1;
                    
                    // Look for a stone directly above the empty cell
                    // 'rotatedBox[i][j]'
                    for (int k = i - 1; k >= 0; --k){
                        if (rotatedBox[k][j] == '*')
                            break;  // Obstacle blocks any stones above
                        
                        if (rotatedBox[k][j] == '#'){   // Stone found with no obstacles in between
                            nextRowWithStone = k;
                            break;
                        }
                    }
                    
                    // If a stone was found above, let it fall into the empty cell 'rotatedBox[i][j]'
                    if (nextRowWithStone != -1){
                        swap(rotatedBox[nextRowWithStone][j], rotatedBox[i][j]);
                    }
                }
            }
        }
        
        return rotatedBox;
    }
};