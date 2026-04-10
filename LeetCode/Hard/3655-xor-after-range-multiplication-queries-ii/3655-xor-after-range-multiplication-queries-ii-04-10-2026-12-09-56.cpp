class Solution {
private:
    const int mod = 1e9 + 7;
    using ll = long long;
    int pow(ll x, ll y) {
        ll res = 1;
        for (; y; y >>= 1) {
            if (y & 1) res = res * x % mod;
            x = x * x % mod;
        }

        return res;
    }

public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), T = sqrt(n);
        vector<vector<vector<int>>> groups(T);

        for (auto& q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            if (k < T) groups[k].push_back({l, r, v});
            else {
                for (int i = l; i <= r; i += k) nums[i] = 1ll * nums[i] * v % mod;
            }
        }

        vector<ll> diff(n + T);
        for (int k = 1; k < T; ++k) {
            if (groups[k].empty()) continue;

            fill(diff.begin(), diff.end(), 1);
            for (auto& q : groups[k]) {
                int l = q[0], r = q[1], v = q[2];
                diff[l] = diff[l] * v % mod;
                int R = ((r - l) / k + 1) * k + l;
                diff[R] = diff[R] * pow(v, mod - 2) % mod;
            }

            for (int i = k; i < n; ++i) 
                diff[i] = diff[i] * diff[i - k] % mod;
            
            for (int i = 0; i < n; ++i) nums[i] = 1ll * nums[i] * diff[i] % mod;
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) ans ^= nums[i];
        return ans;
    }
};