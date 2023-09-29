class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if (nums.size() == 1)
            return true;
        
        int n = nums.size();
        bool increasing = false, decreasing = false;
        
        for (int i = 0; i < n - 1; ++i){
            if (nums[i] >= nums[i + 1]){
                if (i == n - 2)
                    increasing = true;
            }
            else
                break;
        }
        
        for (int i = 0; i < n - 1; ++i){
            if (nums[i] <= nums[i + 1]){
                if (i == n - 2)
                    decreasing = true;
            }
            else
                break;
        }
        
        return increasing || decreasing;
    }
};