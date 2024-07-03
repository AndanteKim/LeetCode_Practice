class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size(), minDiff = INT_MAX;
        if (n <= 4) return 0;
        
        // Partially sort the first four elements
        partial_sort(nums.begin(), nums.begin() + 4, nums.end());
        
        // Find the 4th largest element
        nth_element(nums.begin() + 4, nums.begin() + (n - 4), nums.end());
        
        // Sort the last four elements
        sort(nums.begin() + (n - 4), nums.end());
        
        // Four scenarios to compute the minimum difference
        for (int left = 0, right = n - 4; left < 4; ++left, ++right)
            minDiff = min(minDiff, nums[right] - nums[left]);
        
        return minDiff;
    }
};