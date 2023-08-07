class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowLeft = 0, rowRight = matrix.size();
        
        while (rowLeft < rowRight){
            int rowMid = rowLeft + ((rowRight - rowLeft) >> 1);
            int colLeft = 0, colRight = matrix[0].size(), colMid;
            while (colLeft < colRight){
                colMid = (colLeft + ((colRight - colLeft) >> 1));
                if (matrix[rowMid][colMid] == target) return true;
                if (matrix[rowMid][colMid] < target) colLeft = colMid + 1;
                else colRight = colMid;
            }
            if (matrix[rowMid][colMid] < target) rowLeft = rowMid + 1;
            else rowRight = rowMid;
        }
        
        return false;
    }
};