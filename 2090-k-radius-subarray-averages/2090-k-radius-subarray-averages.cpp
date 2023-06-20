typedef long long ll;

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int radius = 2 * k + 1, n = nums.size(), left = 0;
        ll total = 0;
        vector<int> ans(n, -1);
        
        for (int right = 0; right < nums.size(); ++right){
            total += nums[right];
            while (right - left >= radius - 1){
                ans[k + left] = total / radius;
                total -= nums[left];
                ++left;
            }
        }
        
        return ans;
    }
};