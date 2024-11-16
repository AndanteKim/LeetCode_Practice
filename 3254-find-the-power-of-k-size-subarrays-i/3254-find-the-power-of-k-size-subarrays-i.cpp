class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if (k == 1)
            return nums;    // If k is 1, every single element is a valid subarray
        
        size_t length = nums.size();
        vector<int> ans(length - k + 1, -1);
        
        int consecutiveCount = 1;   // Count of consecutive elements
        for (int i = 0; i < length - 1; ++i){
            if (nums[i] + 1 == nums[i + 1])
                ++consecutiveCount;
            else
                consecutiveCount = 1;       // Reset count if not consecutive
            
            // If we've enough consecutive elements, update the result
            if (consecutiveCount >= k)
                ans[i - k + 2] = nums[i + 1];       // Update the max element
        }
        
        return ans;
    }
};