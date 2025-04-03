class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0;
        int imax = 0, dmax = 0, n = nums.size();

        for (int k = 0; k < n; ++k){
            ans = max(ans, (long long)dmax * nums[k]);
            dmax = max(dmax, imax - nums[k]); 
            imax = max(imax, nums[k]);
        }

        return ans;
    }
};