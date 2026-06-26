typedef long long ll;

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<ll> pre(2 * n + 1);
        pre[n] = 1;
        int cnt = n;
        ll ans = 0, preSum = 0;

        for (int i = 0; i < n; ++i) {
            if (nums[i] == target) {
                preSum += pre[cnt++];
                
            }
            else {
                preSum -= pre[--cnt];
            }
            ++pre[cnt];

            ans += preSum;
        }

        return ans;
    }
};