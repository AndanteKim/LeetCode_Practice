class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size(), mod = 1'000'000'007, ans = 0;
        sort(nums.begin(), nums.end());

        vector<int> power(n);
        power[0] = 1;
        for (int i = 1; i < n; ++i) power[i] = (power[i - 1] * 2) % mod;

        for (int left = 0; left < n; ++left){
            // Find the insertion position for 'target - nums[left]'
            // 'right' equals the insertion index minus - 1.
            int right = upper_bound(nums.begin(), nums.end(), target - nums[left]) - nums.begin() - 1;
            if (right >= left) ans = (ans + (long long)power[right - left]) % mod;
        }

        return ans % mod;
    }
};