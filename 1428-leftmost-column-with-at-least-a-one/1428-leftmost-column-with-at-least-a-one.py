# """
# This is BinaryMatrix's API interface.
# You should not implement it, or speculate about its implementation
# """
#class BinaryMatrix(object):
#    def get(self, row: int, col: int) -> int:
#    def dimensions(self) -> list[]:

class Solution:
    def leftMostColumnWithOne(self, binaryMatrix: 'BinaryMatrix') -> int:
        rows, cols = binaryMatrix.dimensions()
        smallest_idx = cols
        
        for row in range(rows):
            # Binary Search for the first 1 in the row.
            lo, hi = 0, cols - 1
            
            while lo < hi:
                mid = (lo + hi) >> 1
                if binaryMatrix.get(row, mid) == 0:
                    lo = mid + 1
                else:
                    hi = mid
            
            # If the last element in the search space is a 1, then this row
            # contained a 1.
            if binaryMatrix.get(row, lo) == 1:
                smallest_idx = min(smallest_idx, lo)
                
        # If smallest_idx is the still set to cols, then there were no 1's in the grid
        return -1 if smallest_idx == cols else smallest_idx
        