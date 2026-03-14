typedef long long ll;

class Solution {
private:
    static constexpr double eps = 1e-7;

public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int maxWorkerTime = *max_element(workerTimes.begin(), workerTimes.end());
        ll l = 1, r = (static_cast<ll>(maxWorkerTime) * mountainHeight * (mountainHeight + 1)) >> 1;
        ll ans = 0;

        while (l <= r) {
            ll mid = (l + r) >> 1, cnt = 0;

            for (int t : workerTimes) {
                ll work = mid / t;
                // Find the largest k such that 1 + 2 + ... + k <= work
                ll k = (-1.0 + sqrt(1 + work * 8)) / 2 + eps;
                cnt += k;
            }

            if (cnt >= mountainHeight) {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }

        return ans;
    }
};