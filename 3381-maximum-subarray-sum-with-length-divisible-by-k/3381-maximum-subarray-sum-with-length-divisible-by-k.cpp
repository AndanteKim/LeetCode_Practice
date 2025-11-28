typedef long long ll;

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = std::numeric_limits<ll>::min(), prefixSum = 0;
        vector<long long> kSum(k, LONG_LONG_MAX >> 1);
        kSum[k - 1] = 0;

        for (int i = 0; i < n; ++i) {
            prefixSum += nums[i];
            ans = max(ans, prefixSum - kSum[i % k]);
            kSum[i % k] = min(kSum[i % k], prefixSum);
        }

        return ans;
    }
};