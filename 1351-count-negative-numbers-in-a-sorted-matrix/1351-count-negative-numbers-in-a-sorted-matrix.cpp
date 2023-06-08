class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int r = grid.size() - 1, c = grid[0].size(), ans = 0, i = 0;
        
        while (r >= 0 && i < c){
            if (grid[r][i] >= 0) ++i;
            else{
                ans += c - i;
                --r;
            }
        }
        
        return ans;
    }
};