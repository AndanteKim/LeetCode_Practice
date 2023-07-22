class Solution {
private:
    vector<pair<int, int>> moves{{2, 1}, {1, 2}, {-2, 1}, {2, -1}, {1, -2}, {-1, 2}, {-1, -2}, {-2, -1}};
    int n;
    double dp(int r, int c, int k, vector<vector<vector<double>>>& memo){
        if (r < 0 || r >= n || c < 0 || c >= n) return 0;
        if (k == 0) return 1;
        
        if (memo[k][r][c] != -1.0) return memo[k][r][c];
        double prob = 0;
        for (auto &[dr, dc] : moves){
            prob += dp(r + dr, c + dc, k - 1, memo);
        }
        
        return memo[k][r][c] = prob / 8;
    }
    
public:
    double knightProbability(int n, int k, int row, int column) {
        this -> n = n;
        vector memo(k + 1, vector(n, vector<double>(n, -1)));
        return dp(row, column, k, memo);
    }
};