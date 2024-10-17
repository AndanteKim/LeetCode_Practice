class Solution {
public:
    int maximumSwap(int num) {
        string numStr = to_string(num);
        int n = numStr.size();
        // Stores the index of the max digits from current position to the end
        vector<int> maxRightIndex(n, 0);
        
        // First pass: Populate maxRightIndex with the index of the largest
        // digit to the right of each position.
        maxRightIndex[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; --i){
            maxRightIndex[i] = numStr[maxRightIndex[i + 1]] < numStr[i]? i : maxRightIndex[i + 1];
        }
        
        // Second pass: Find the first place where we can swap to maximize the number
        for (int i = 0; i < n; ++i){
            if (numStr[i] < numStr[maxRightIndex[i]]){
                // Swap to maximize the number
                swap(numStr[i], numStr[maxRightIndex[i]]);
                // Return the new number immediately after the swap
                return stoi(numStr);
            }
        }
        
        // Return the original number if no swap can maximize it.
        return num;
    }
};