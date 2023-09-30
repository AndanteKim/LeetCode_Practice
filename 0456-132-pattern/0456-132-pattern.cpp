class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if (nums.size() < 3)
            return false;
        int n = nums.size();
        vector<int> minArr(n);
        minArr[0] = nums[0];
        for (int i = 1; i < n; ++i)
            minArr[i] = min(minArr[i - 1], nums[i]);
        
        int k = n;
        for (int j = n - 1; j >= 0; --j){
            if (nums[j] <= minArr[j]) continue;
            
            while (k < n && nums[k] <= minArr[j])
                ++k;
            
            if (k < n && nums[k] < nums[j])
                return true;
            
            nums[--k] = nums[j];
        }
        
        return false;
    }
};