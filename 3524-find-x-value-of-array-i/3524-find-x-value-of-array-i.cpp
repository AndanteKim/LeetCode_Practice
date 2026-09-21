typedef long long ll;

class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<ll> ans(k), dp(k);

        for (int i = 0; i < n; ++i) {
            vector<ll> ndp(k);      // Current State(Rolling Array)
            ++ndp[nums[i] % k];

            for (int r = 0; r < k; ++r) {
                ndp[(ll)r * nums[i] % k] += dp[r];
            }

            dp = move(ndp);
            for (int r = 0; r < k; ++r) ans[r] += dp[r];
        }

        return ans;
    }
};