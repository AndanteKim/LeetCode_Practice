class Solution {
public:
    int maximumSwap(int num) {
        // Convert num to string for easy manipulation
        string numStr = to_string(num);
        
        // Track the maximum number found
        int maxNum = num, n = numStr.size();
        
        // Try all possible swaps
        for (int i = 0; i < n; ++i){
            for (int j = i + 1; j < n; ++j){
                // Swap digits at index i and j
                swap(numStr[i], numStr[j]);
                
                // Update maxNum if the new number is larger
                maxNum = max(maxNum, stoi(numStr));
                
                // Swap back to restore the original string
                swap(numStr[i], numStr[j]);
            }
        }
        
        // Return the largest number after all possible swaps
        return maxNum;
    }
};