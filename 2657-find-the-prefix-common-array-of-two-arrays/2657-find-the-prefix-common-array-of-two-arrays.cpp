class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> prefixCommonArray(n);

        // Initialize sets to store elements from A and B
        unordered_set<int> elementsA, elementsB;
        
        // Iterate through the elements of both arrays
        for (int currIndex = 0; currIndex < n; ++currIndex){
            // Add current elements from A and B to respective sets
            elementsA.insert(A[currIndex]);
            elementsB.insert(B[currIndex]);
            
            int commonCount = 0;
            
            // Count common elements between the sets
            for (int elem : elementsA){
                if (elementsB.count(elem))
                    ++commonCount;
            }

            // Store the count of common elements for the current prefix
            prefixCommonArray[currIndex] = commonCount;
        }
        
        // Return the final array with counts of common elements in each prefix
        return prefixCommonArray;
    }
};