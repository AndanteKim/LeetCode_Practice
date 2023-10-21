class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        vector<int> dp(nums.size());
        map<int, int> window;
        window[0] = 0;
        
        for (int i = 0; i < nums.size(); ++i){
            dp[i] = nums[i] + window.rbegin() -> first;
            ++window[dp[i]];
            
            if (i >= k){
                --window[dp[i - k]];
                if (window[dp[i - k]] == 0)
                    window.erase(dp[i - k]);
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};