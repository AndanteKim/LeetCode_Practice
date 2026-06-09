class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long mx = std::numeric_limits<long long>::min(), mn = std::numeric_limits<long long>::max();

        for (int num : nums) {
            mx = max(mx, (long long)num);
            mn = min(mn, (long long)num);
        }

        return (mx - mn) * k;
    }
};