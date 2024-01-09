/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        auto it = binaryMatrix.dimensions();
        int rows = it[0], cols = it[1], smallestIndex = cols;
        
        for (int row = 0; row < rows; ++row){
            // binary search for the first one in the row
            int lo = 0, hi = cols - 1;
            while (lo < hi){
                int mid = (lo + hi) >> 1;
                if (binaryMatrix.get(row, mid) == 0)
                    lo = mid + 1;
                else
                    hi = mid;
            }
            
            // If the last element is in the search space is 1, then this row contained one.
            if (binaryMatrix.get(row, lo) == 1)
                smallestIndex = min(smallestIndex, lo);
        }
        
        // If smallestIndex is the still set to cols, then there is no one in the grid.
        return (smallestIndex == cols)? -1: smallestIndex;
    }
};