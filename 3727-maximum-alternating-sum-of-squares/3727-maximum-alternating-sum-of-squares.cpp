typedef long long ll;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        ll ans = 0;
        int n = nums.size();
        vector<int> absNums(n);
        for (int i = 0; i < n; ++i) absNums[i] = abs(nums[i]);
        sort(absNums.begin(), absNums.end());

        int j = n - 1;
        for (int i = 0; i < (n >> 1); ++i) {
            ans -= absNums[i] * absNums[i];
            ans += absNums[j] * absNums[j--];
        }

        if (n % 2) ans += absNums[j] * absNums[j];

        return ans;
    }
};