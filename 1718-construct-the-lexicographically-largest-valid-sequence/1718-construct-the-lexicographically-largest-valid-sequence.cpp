class Solution {
private:
    int targetNumber;
    
    // Recursive function to generate the desired sequence
    bool findLexicographicallyLargestSequence(int currIndex, vector<int>& resultSequence, vector<bool>& isNumberUsed){
        // If we've filled all positions, return true indicatingsuccess
        if (currIndex == resultSequence.size())
            return true;

        // If the current position is already filled, move to the next index
        if (resultSequence[currIndex] != 0){
            return findLexicographicallyLargestSequence(currIndex + 1, resultSequence, isNumberUsed);
        }

        // Attempt to place numbers from targetNumber to 1 for a lexicographically largest result
        for (int numberToPlace = targetNumber; numberToPlace >= 1; --numberToPlace){
            if (isNumberUsed[numberToPlace]) continue;

            isNumberUsed[numberToPlace] = true;
            resultSequence[currIndex] = numberToPlace;

            // If placing number 1, move to the next index directly
            if (numberToPlace == 1){
                if (findLexicographicallyLargestSequence(currIndex + 1, resultSequence, isNumberUsed)) return true;
            }
            // Place the larger numbers at two positions if valid
            else if (numberToPlace + currIndex < resultSequence.size() && resultSequence[numberToPlace + currIndex] == 0){
                resultSequence[numberToPlace + currIndex] = numberToPlace;
                if (findLexicographicallyLargestSequence(currIndex + 1, resultSequence, isNumberUsed)) return true;
                
                // Undo the placement for backtracking
                resultSequence[numberToPlace + currIndex] = 0;
            }

            // Undo current placement and mark the number as unused
            isNumberUsed[numberToPlace] = false;
            resultSequence[currIndex] = 0;
        }

        return false;
    }

public:
    vector<int> constructDistancedSequence(int n) {
        this -> targetNumber = n;
        
        // Initialize the result sequence with size 2 * n - 1 filled with 0s
        vector<int> resultSequence(2 * n - 1);

        // Keep track of which numbers are already placed in the sequence
        vector<bool> isNumberUsed(n + 1, false);

        // Start recursive backtracking to construct the sequence
        findLexicographicallyLargestSequence(0, resultSequence, isNumberUsed);

        return resultSequence;
    }
};