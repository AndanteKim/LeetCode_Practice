class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<pair<int, int>> dirs{{2, 1}, {1, 2}, {2, -1}, {-2, 1}, {-2, -1}, {1, -2}, {-1, 2}, {-1, -2}};
        vector dp(k + 1, vector(n, vector<double>(n, 0)));
        dp[0][row][column] = 1.0;
        
        for (int moves = 1; moves <= k; ++moves){
            for (int r = 0; r < n; ++r){
                for (int c = 0; c < n; ++c){
                    for (auto& [dr, dc] : dirs){
                        int prevR = r + dr, prevC = c + dc;
                        if (prevR < 0 || prevR >= n || prevC < 0 || prevC >= n) continue;
                        dp[moves][r][c] += dp[moves - 1][prevR][prevC];
                    }
                    dp[moves][r][c] /= 8;
                }
            }
        }
        
        double prob = 0.0;
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                prob += dp[k][i][j];
            }
        }
        
        return prob;
    }
};