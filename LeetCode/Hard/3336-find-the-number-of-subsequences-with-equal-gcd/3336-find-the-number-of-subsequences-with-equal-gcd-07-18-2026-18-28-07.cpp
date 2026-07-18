class Solution {
private:
    static constexpr int MOD = 1'000'000'007;

public:
    int subsequencePairCount(vector<int>& nums) {
        int m = *max_element(nums.begin(), nums.end());
        vector dp(m + 1, vector<int>(m + 1));
        dp[0][0] = 1;

        for (int num : nums) {
            vector ndp(m + 1, vector<int>(m + 1));

            for (int j = 0; j <= m; ++j) {
                int div1 = gcd(j, num);

                for (int k = 0; k <= m; ++k) {
                    int val = dp[j][k];

                    if (val == 0) continue;
                    int div2 = gcd(k, num);
                    ndp[j][k] = (ndp[j][k] + val) % MOD;
                    ndp[div1][k] = (ndp[div1][k] + val) % MOD;
                    ndp[j][div2] = (ndp[j][div2] + val) % MOD;
                }

            }
            dp = ndp;
        }

        int ans = 0;
        for (int i = 1; i <= m; ++i) ans = ((long long)ans + dp[i][i]) % MOD;
        
        return ans;
    }
};