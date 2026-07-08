typedef long long ll;

const int MOD = 1e9 + 7, MAX_N = 100'001;
ll pow10[MAX_N];

// Init runs only once for all test cases
int init = []() {
    pow10[0] = 1;
    for (int i = 1; i < MAX_N; ++i) {
        pow10[i] = (pow10[i - 1] * 10) % MOD;
    }
    return 0;
}();

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<ll> x(n + 1);
        vector<int> sum(n + 1), cnt(n + 1);

        for (int i = 0; i < n; ++i) {
            int d = s[i] - 48;
            x[i + 1] = (d > 0)? (x[i] * 10 + d) % MOD : x[i];
            sum[i + 1] = sum[i] + d;
            cnt[i + 1] = cnt[i] + (d > 0);
        }

        int m = queries.size();
        vector<int> ans(m);

        for (int i = 0; i < m; ++i) {
            int l = queries[i][0], r = queries[i][1] + 1;
            int length = cnt[r] - cnt[l];

            ll valX = (x[r] - x[l] * pow10[length] % MOD + MOD) % MOD;
            ll valSum = sum[r] - sum[l];
            ans[i] = (valX * valSum) % MOD;
        }

        return ans;
    }
};