class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size(), i = 0;
        
        // Use cycle sort to place elements
        // at corresponding index to value
        while (i < n){
            int correctIdx = nums[i] - 1;
            if (nums[i] != nums[correctIdx])
                swap(nums[i], nums[correctIdx]);
            else
                ++i;
        }
        
        // Any elements not at the index corresponding to their value are duplicates
        for (int i = 0; i < n; ++i){
            if (nums[i] != i + 1)
                ans.push_back(nums[i]);
        }
        
        return ans;
    }
};