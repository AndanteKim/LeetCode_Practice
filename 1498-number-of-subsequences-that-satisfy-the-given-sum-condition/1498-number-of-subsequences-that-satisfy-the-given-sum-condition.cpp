class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size(), ans = 0, mod = 1'000'000'007;
        vector<int> power(n);
        power[0] = 1;
        for (int i = 1; i < n; ++i) power[i] = power[i - 1] * 2 % mod;

        sort(nums.begin(), nums.end());
        int left = 0, right = n - 1;

        while (left <= right){
            if (nums[left] + nums[right] <= target){
                ans = (ans + power[right - left]) % mod;
                ++left;
            }
            else --right;
        }

        return ans;
    }
};