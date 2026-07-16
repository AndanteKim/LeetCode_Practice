typedef long long ll;

class Solution {
private:
    ll gcd(ll a, ll b) {
        if (a < b) return gcd(b, a);

        while (b != 0) {
            ll temp = b;
            b = a % b;
            a = temp;
        }

        return a;
    }

public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size(), mx = 0;
        vector<ll> prefixGcd(n);

        for (int i = 0; i < n; ++i) {
            mx = max(mx, nums[i]);
            prefixGcd[i] = gcd(mx, nums[i]);
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        ll ans = 0;
        for (int i = 0; i < (n >> 1); ++i) {
            ans += gcd(prefixGcd[i], prefixGcd[n - 1 - i]);
        }

        return ans;
    }
};