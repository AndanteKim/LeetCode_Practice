class Solution {
private:
    // Return the maximum values in the 3 x 3 matrix with top-left as (x, y)
    int findMax(vector<vector<int>>& grid, int x, int y){
        int maxElem = 0;
        for (int i = x; i < x + 3; ++i){
            for (int j = y; j < y + 3; ++j)
                maxElem = max(maxElem, grid[i][j]);
        }
        
        return maxElem;
    }
    
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> maxLocal(n - 2, vector<int>(n - 2));
        
        for (int i = 0; i < n - 2; ++i){
            for (int j = 0; j < n - 2; ++j)
                maxLocal[i][j] = max(maxLocal[i][j], findMax(grid, i, j));
        }
        
        return maxLocal;
    }
};