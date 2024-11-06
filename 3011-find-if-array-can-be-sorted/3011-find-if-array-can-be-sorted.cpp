class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        
        // Create a copy of the original array
        vector<int> values(nums.begin(), nums.end());
        
        // First Pass: Iterate from left to right
        // Goal: Move the maximum value of each segment as far right as possible
        for (int i = 0; i < n - 1; ++i){
            if (values[i] <= values[i + 1])
                continue;
            
            // Check if the current and next element have the same number of set bits
            if (__builtin_popcount(values[i]) == __builtin_popcount(values[i + 1]))
                // Swap if they do
                swap(values[i], values[i + 1]);
            else
                return false;   // Reutn false if they cannot be swapped
        }
        
        // Second Pass: Iterate from right to left
        // Goal: Move the minimum value of each segment as far left as possible
        for (int i = n - 1; i > 0; --i){
            if (values[i] >= values[i - 1])
                continue;
            
            // Check if the current and previous element have the same number of set bits
            if (__builtin_popcount(values[i]) == __builtin_popcount(values[i - 1]))
                // Swap if they do
                swap(values[i], values[i - 1]);
            else
                return false;   // Return false if they cannot be swapped
        }
        
        // If both passes complete without returning false, the array can be sorted
        return true;
    }
};