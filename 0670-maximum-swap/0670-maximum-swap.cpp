class Solution {
public:
    int maximumSwap(int num) {
        string numStr = to_string(num);
        int n = numStr.size(), maxRightIndex = -1, swapIndex1 = -1, swapIndex2 = -1;
        
        // Traverse the string from right to left, tracking the max digit and potential swap
        for (int i = n - 1; i >= 0; --i){
            if (maxRightIndex == -1 || numStr[i] - '0' > numStr[maxRightIndex] - '0'){
                // Update the index of the max digit
                maxRightIndex = i;
            }
            else if (numStr[i] - '0' < numStr[maxRightIndex] - '0'){
                // Mark the smaller digit for swapping
                swapIndex1 = i;
                // Mark the larger digit for swapping
                swapIndex2 = maxRightIndex;
            }
        }
        
        // Perform the swap if a valid swap is found
        if (swapIndex1 != -1 && swapIndex2 != -1){
            swap(numStr[swapIndex1], numStr[swapIndex2]);
        }
        
        // Return the new number or the original if no swap occurred
        return stoi(numStr);
    }
};