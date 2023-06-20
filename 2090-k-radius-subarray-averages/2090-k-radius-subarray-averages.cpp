typedef long long ll;

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n, -1);
        if (2 * k + 1 > n) return ans;
        ll windowSum = accumulate(nums.begin(), nums.begin() + 2 * k + 1, 0ll);
        ans[k] = windowSum / (2 * k + 1);
        
        for (int i = 2 * k + 1; i < n; ++i){
            windowSum = windowSum - nums[i - (2 * k + 1)] + nums[i];
            ans[i - k] = windowSum / (2 * k + 1);
        }
        
        return ans;
    }
};