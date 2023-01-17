class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int length = nums.size();
        
        vector<int> tot(length, 0);
        tot[0] = nums[0];
        for (int i = 1; i < length; ++i) tot[i] = tot[i-1] + nums[i];
        
        double ans = (double)tot[k-1]/k;
        for (int i = k; i < nums.size(); ++i) ans = max(ans, (double)(tot[i] - tot[i-k])/k);
        return ans;
    }
};