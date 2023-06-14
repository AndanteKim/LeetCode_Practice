typedef long long ll;

class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        ll left = 1, right = accumulate(batteries.begin(), batteries.end(), 0ll) / n;
        
        while (left < right){
            ll target = right - ((right - left) >> 1);
            ll extra = 0;
            for (ll power : batteries) extra += min(power, target);
            if (extra / n >= target) left = target;
            else right = target - 1;
        }
        
        return left;
    }
};