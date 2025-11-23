class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector dp(n + 1, vector<int>(3, std::numeric_limits<int>::min()));
        dp[0][0] = 0;

        for (int i = 0; i < n; ++i) {
            int x = nums[i];

            for (int mod = 0; mod < 3; ++mod)
                dp[i + 1][mod] = max(x + dp[i][(mod + x) % 3], dp[i][mod]);
        }

        return dp[n][0];
    }
};