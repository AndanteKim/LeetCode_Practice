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
        int rows = it[0], cols = it[1];
        // Set pointers to the top-right corner
        int currentRow = 0, currentCol = cols - 1;
        
        // Repeat the search until it goes off the grid
        while (currentRow < rows && currentCol >= 0){
            if (binaryMatrix.get(currentRow, currentCol) == 0)
                ++currentRow;
            else
                --currentCol;
        }
        
        // If we never left the last column, it must have been all 0's.
        return (currentCol == cols - 1)? -1: currentCol + 1;
    }
};