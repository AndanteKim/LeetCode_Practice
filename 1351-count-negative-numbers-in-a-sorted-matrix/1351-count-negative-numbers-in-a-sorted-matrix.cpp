class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        
        for (int i = 0; i < m; ++i){
            int left = 0, right = n;
            while (left < right){
                int mid = left + (right - left) / 2;
                if (grid[i][mid] >= 0) left = mid + 1;
                else right = mid;
            }
            ans += n - left;
        }
        
        return ans;
    }
};