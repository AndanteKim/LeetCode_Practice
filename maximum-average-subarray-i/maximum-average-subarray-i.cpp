class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int curr = 0, ans;
        for (int i = 0; i < k; ++i) curr += nums[i];
        
        ans = curr;
        for (int i = k; i < nums.size(); ++i){
            curr = curr - nums[i-k] + nums[i];
            ans = max(ans, curr);
        }
        
        return (double)ans/k;
    }
};