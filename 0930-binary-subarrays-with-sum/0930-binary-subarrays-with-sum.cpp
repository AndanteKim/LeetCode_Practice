class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int i_lo = 0, i_hi = 0, sum_lo = 0, sum_hi = 0, ans = 0;
        
        for (int i = 0; i < nums.size(); ++i){
            sum_lo += nums[i];
            while (i_lo < i && sum_lo > goal){
                sum_lo -= nums[i_lo];
                ++i_lo;
            }
            
            sum_hi += nums[i];
            while (i_hi < i && (sum_hi > goal || sum_hi == goal && !nums[i_hi])){
                sum_hi -= nums[i_hi];
                ++i_hi;
            }
            
            if (sum_lo == goal) ans += i_hi - i_lo + 1;
        }
        
        return ans;
    }
};