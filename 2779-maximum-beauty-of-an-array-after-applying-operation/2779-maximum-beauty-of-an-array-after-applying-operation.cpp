class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        // Base case: If there's only one element, the maximum beauty is 1.
        if (nums.size() == 1)
            return 1;
        
        // Find the maximum value in the array
        int n = nums.size(), maxVal = *max_element(nums.begin(), nums.end());
        
        // Create an array to keep track of the count changes
        vector<int> count(maxVal + 1);
        
        // Update the count array for each value's range [val - k, val + k]
        for (int num : nums){
            ++count[max(num - k, 0)];   // Increment at the start of the range
            --count[min(num + k + 1, maxVal)];  // Decrement after the range
        }
        
        int maxBeauty = 0, currSum = 0;     // Tracks the running sum of counts
        
        // Calculate the prefix sum and find the maximum value
        for (int val : count){
            currSum += val;
            maxBeauty = max(maxBeauty, currSum);
        }
        
        return maxBeauty;
    }
};