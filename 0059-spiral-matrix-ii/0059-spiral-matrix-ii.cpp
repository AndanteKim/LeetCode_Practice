class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int i = 1;
        int left = 0, right = n - 1, up = 0, down = n - 1;
        while (i <= n * n){
            for (int col = left; col <= right; ++col){
                ans[up][col] = i;
                ++i;
            }
            for (int row = up + 1; row <= down; ++row){
                ans[row][right] = i;
                ++i;
            }
            if (up != down){
                for (int col = right - 1; col >= left; --col){
                    ans[down][col] = i;
                    ++i;
                }
            }
            
            if (left != right){
                for (int row = down - 1; row > up; --row){
                    ans[row][left] = i;
                    ++i;
                }
            }
            
            ++left, --right, ++up, --down;
        }
        return ans;
    }
};