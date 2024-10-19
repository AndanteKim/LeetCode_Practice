class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        // Calculate the maximum possible OR value
        int n = nums.size(), maxOrVal = 0;
        
        for (int num : nums)
            maxOrVal |= num;
        
        int totalSubsets = (1 << n);    // 2^n subsets
        int subsetsWithMaxOr = 0;
        
        // Iterate through all possible subsets
        for (int subsetMask = 0; subsetMask < totalSubsets; ++subsetMask){
            int currOrVal = 0;
            
            // Calculate OR value for the current subset
            for (int i = 0; i < n; ++i)
                if (((subsetMask >> i) & 1) == 1)
                    currOrVal |= nums[i];
                    
            // If current subset's OR equals maxOrVal, increment count
            if (currOrVal == maxOrVal) ++subsetsWithMaxOr;
        }
        
        return subsetsWithMaxOr;
    }
};