class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff = INT_MAX;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); ++i){
            int lo = i + 1, hi = nums.size() - 1;
            
            while (lo < hi){
                int sum = nums[i] + nums[lo] + nums[hi];
                
                if (abs(target - sum) < abs(diff)) diff = target - sum;
                
                if (sum < target) ++lo;
                else --hi;
            }
            
            // If there is the exact target by summation of three vars.
            if (diff == 0) break;
        }
        
        return target - diff;
    }
};