#define ull unsigned long long

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0, left = 0, right = n - 1, mod = pow(10, 9) + 7;
        vector<int> pows(n, 1);
        for (int i = 1; i < n; ++i) pows[i] = pows[i - 1] * 2 % mod;
        while (left <= right){
            if (nums[left] + nums[right] <= target){
                ans = (ans + pows[right - left]) % mod;
                ++left;
            }
            else --right;
        }
        
        return ans;
    }
};