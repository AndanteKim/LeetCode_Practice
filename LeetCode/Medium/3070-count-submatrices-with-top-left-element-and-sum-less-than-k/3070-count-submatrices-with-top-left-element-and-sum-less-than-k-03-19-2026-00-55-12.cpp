class Solution {
private:
    int sumLeft(vector<vector<int>>& grid, int i, int j) {
        int sum = 0;
        for (int k = 0; k <= j; ++k) sum += grid[i][k];
        return sum;
    }

    int sumUp(vector<vector<int>>& grid, int i, int j) {
        int sum = 0;
        for (int k = 0; k <= i; ++k) sum += grid[k][j];
        return sum;
    }

public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size(), leftBound = n - 1;
        int currSum = 0, ans = 0;

        for (int i = 0; i < m; ++i){
            currSum += sumLeft(grid, i, leftBound);
        
            while (currSum > k) {
                currSum -= sumUp(grid, i, leftBound--);
            }
            ans += (leftBound + 1);
        }

        return ans;
    }
};