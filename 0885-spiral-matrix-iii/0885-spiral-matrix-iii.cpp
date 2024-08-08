class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int count = 0, currR = rStart, currC = cStart, magnitude = 1;
        vector<vector<int>> ans;
        
        while (count < rows * cols){
            // Right
            for (int c = 0; c < magnitude && count < rows * cols; ++c){
                if (0 <= currR && currR < rows && 0 <= currC && currC < cols){
                    ans.push_back({currR, currC});    
                    ++count;
                }
                ++currC;
            }
            
            // Down
            for (int r = 0; r < magnitude && count < rows * cols; ++r){
                if (0 <= currR && currR < rows && 0 <= currC && currC < cols){
                    ans.push_back({currR, currC});    
                    ++count;
                }
                ++currR;
            }
            
            ++magnitude;
            // Left
            for (int c = 0; c < magnitude && count < rows * cols; ++c){
                if (0 <= currR && currR < rows && 0 <= currC && currC < cols){
                    ans.push_back({currR, currC});
                    ++count;
                }
                --currC;
            }
            
            // Up
            for (int r = 0; r < magnitude && count < rows * cols; ++r){
                if (0 <= currR && currR < rows && 0 <= currC && currC < cols){
                    ans.push_back({currR, currC});    
                    ++count;
                }
                --currR;
            }
            ++magnitude;
        }
        
        return ans;
    }
};