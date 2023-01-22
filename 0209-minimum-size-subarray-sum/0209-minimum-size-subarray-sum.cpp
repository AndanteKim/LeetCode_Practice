class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), ans = INT_MAX;
        vector<int> sums(n+1, 0);
        for (int i = 1; i <= n; ++i) sums[i] = sums[i-1] + nums[i-1];
        
        for (int i = 1; i <= n; ++i){
            int to_find = target + sums[i-1];
            auto bound = lower_bound(sums.begin(), sums.end(), to_find);
            if (bound != sums.end()) ans = min(ans, static_cast<int>(bound - (sums.begin() + i - 1)));
        }
        return (ans != INT_MAX) ? ans : 0;
    }
};