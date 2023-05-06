#define ll long long
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int ans = 0, n = nums.size(), mod = pow(10, 9) + 7;
        vector<int> pows(n, 1);
        for (int i = 1; i < n; ++i) pows[i] = pows[i - 1] * 2 % mod;
        sort(nums.begin(), nums.end());
        
        int left = 0, right = n - 1;
        
        while (left <= right){
            if (nums[left] + nums[right] > target) --right;
            else ans = (ans + pows[right - left++]) % mod;
        }
        
        return ans;
    }
};