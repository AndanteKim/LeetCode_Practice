class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int> indices(n);
        // Initialize the array with indices
        iota(indices.begin(), indices.end(), 0);
        
        // Sort indices based on the corresponding values in nums and ensure stability.
        sort(indices.begin(), indices.end(), [&](int a, int b){
            if (nums[a] == nums[b]){
                return a < b;
            }
            return nums[a] < nums[b];
        });
        
        // Minimum index encountered so far
        int maxWidth = 0, minIndex = n;
        
        // Calculate maximum width ramp
        for (int i : indices){
            maxWidth = max(maxWidth, i - minIndex);
            minIndex = min(minIndex, i);
        }
        
        return maxWidth;
    }
};