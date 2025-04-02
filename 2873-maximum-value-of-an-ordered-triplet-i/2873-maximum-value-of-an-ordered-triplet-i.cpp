class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();

        for(int k = 2; k < n; ++k){
            int maxPrefix = nums[0];
            for (int j = 1; j < k; ++j){
                ans = max(ans, (long long)(maxPrefix - nums[j]) * nums[k]);
                maxPrefix = max(maxPrefix, nums[j]);
            }
        }

        return ans;
    }
};