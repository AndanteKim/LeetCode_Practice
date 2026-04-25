typedef long long ll;

class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<ll> arr;
        for (const auto& pt : points) {
            int x = pt[0], y = pt[1];
            if (x == 0) arr.push_back(y);
            else if (y == side) arr.push_back(side + x);
            else if (x == side) arr.push_back(3LL * side - y);
            else arr.push_back(4LL * side - x);
        }

        sort(arr.begin(), arr.end());

        auto check = [&](ll limit) -> bool {
        
            for (ll start : arr) {
                ll end = start + 4LL * side - limit, curr = start;

                for (int i = 0; i < k - 1; ++i) {
                    int idx = lower_bound(arr.begin(), arr.end(), curr + limit) - arr.begin();
            
                    if (idx >= arr.size() || arr[idx] > end) {
                        curr = -1;
                        break;
                    }

                    curr = arr[idx];
                }
                if (curr >= 0) return true;
            }

            return false;
        };

        int ans = 0;
        ll lo = 1, hi = side;
        while (lo <= hi) {
            ll mid = lo + ((hi - lo) >> 1);

            if (check(mid)) {
                ans = mid;
                lo = mid + 1;
            }
            else hi = mid - 1;
        }

        return ans;
    }
};