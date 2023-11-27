class Solution {
public:
    int knightDialer(int n) {
        vector<vector<int>> jumps{{4,6}, {6,8}, {7,9},\
        {4,8},{0,3,9},{},{0,1,7},{2,6},{1,3},{2,4}};
        vector<int> prevDp(10, 1);
        int MOD = 1'000'000'007;
        
        for (int remain = 1; remain < n; ++remain){
            vector<int> dp(10);
            
            for (int square = 0; square < 10; ++square){
                int curr = 0;
                for (int nextSquare : jumps[square])
                    curr = (curr + prevDp[nextSquare]) % MOD;
                dp[square] = curr;
            }
            prevDp = dp;
        }
        
        int ans = 0;
        for (int square = 0; square < 10; ++square)
            ans = (ans + prevDp[square]) % MOD;
        return ans;
    }
};