class Solution {
public:
    int knightDialer(int n) {
        vector<vector<int>> jumps{{4,6}, {6,8}, {7,9},\
        {4,8},{0,3,9},{},{0,1,7},{2,6},{1,3},{2,4}};
        int MOD = 1'000'000'007;
        vector<vector<int>> dp(n + 1, vector<int>(10));
        
        for (int square = 0; square < 10; ++square)
            dp[0][square] = 1;
        
        for (int remain = 1; remain <= n; ++remain){
            for (int square = 0; square < 10; ++square){
                int curr = 0;
                for (int nextSquare : jumps[square])
                    curr = (curr + dp[remain - 1][nextSquare]) % MOD;
                dp[remain][square] = curr;
            }
        }
        
        int ans = 0;
        for (int i = 0; i < 10; ++i)
            ans = (ans + dp[n - 1][i]) % MOD;
        
        return ans;
    }
};