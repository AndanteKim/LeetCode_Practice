class Solution {
    int floorMod(int x, int y){
        return ((x % y) + y) % y;
    }
    
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        vector<pair<int, int>> directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int i = 1, d = 0, row = 0, col = 0;
        
        while (i <= n * n){
            ans[row][col] = i++;
            int r = floorMod(row + directions[d].first, n);
            int c = floorMod(col + directions[d].second, n);
            if (ans[r][c] != 0) d = (d + 1) % 4;
            row += directions[d].first;
            col += directions[d].second;
        }
        
        return ans;
    }
};