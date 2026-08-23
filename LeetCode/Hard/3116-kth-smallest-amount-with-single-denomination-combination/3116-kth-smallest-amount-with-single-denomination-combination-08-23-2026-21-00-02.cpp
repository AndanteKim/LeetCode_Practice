class Solution {
public:
    using ll = long long;
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        int m = 1 << n;
        sort(coins.begin(), coins.end());
        vector<int> bitCount(m);
        vector<ll> lcm(m);
        ll l = k, r = 1LL * coins[0] * k + 1;

        for (int mask = 1; mask < m; ++mask) {
            ll currLcm = 1;
            for (int i = 0; i < n; ++i) {
                if ((mask >> i) & 1) {
                    ll tmp = currLcm / gcd(currLcm, coins[i]);
                    if (tmp <= r / coins[i]) currLcm = tmp * coins[i];
                    else {
                        currLcm = r + 1;
                        break;
                    }
                    ++bitCount[mask];
                }
            }
            lcm[mask] = currLcm;
        }

        auto get = [&](ll x) -> ll {
            ll count = 0;
            for (int mask = 1; mask < m; ++mask) {
                if (lcm[mask] > x) continue;
                if (bitCount[mask] & 1) count += x / lcm[mask];
                else count -= x / lcm[mask];
            }

            return count;
        };

        while (l < r) {
            ll mid = (l + r) >> 1;
            if (get(mid) >= k) r = mid;
            else l = mid + 1;
        }

        return l;
    }
};