class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> prefixCommonArray(n);

        // Loop through each index to calculate common elements for each prefix
        for (int currIndex = 0; currIndex < n; ++currIndex){
            int commonCount = 0;
            
            // Compare elements in A and B within the range of current prefix
            for (int aIndex = 0; aIndex < currIndex + 1; ++aIndex){
                for (int bIndex = 0; bIndex < currIndex + 1; ++bIndex){
                    // Check if elements match, and count if they do
                    if (A[aIndex] == B[bIndex]){
                        ++commonCount;
                        break;
                    }
                }
            }
            
            // Store the count of common elements for the current prefix
            prefixCommonArray[currIndex] = commonCount;
        }

        // Return the final array with counts of common elemtns in each prefix
        return prefixCommonArray;
    }
};