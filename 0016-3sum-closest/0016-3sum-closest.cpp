class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff = INT_MAX;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size() && diff != 0; ++i){
            for (int j = i + 1; j < nums.size(); ++j){
                int complement = target - (nums[i] + nums[j]);
                int hi = upper_bound(nums.begin() + j + 1, nums.end(), complement) - nums.begin(), lo = hi - 1;
                
                if (hi < nums.size() && abs(complement - nums[hi]) < abs(diff))
                    diff = complement - nums[hi];
                
                if (j < lo && abs(complement - nums[lo]) < abs(diff))
                    diff = complement - nums[lo];
            }
        }
        
        return target - diff;
    }
};