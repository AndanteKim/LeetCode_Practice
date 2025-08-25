class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        // Base case
        if (mat.size() == 0 || mat[0].size() == 0) return {};

        // Variables to track the size of the matrix
        int R = mat.size(), C = mat[0].size(), r = 0, c = 0;
        
        vector<int> ans, curr;
        
        // We have to go over all the elements in the first
        // row and the last column to cover all possible diagonals
        for (int d = 0; d <= R + C - 1; ++d){
            // Clear the intermediate array everytime we start
            // to process another diagonal
            curr.clear();

            // We need to figure otu the "head" of this diagonal
            // The elements in the first row and the last column
            // are the respective heads.
            r = (d < C)? 0 : d - C + 1;
            c = (d < C)? d : C - 1;
            
            // Iterate until one of the indices goes out of scope
            // Take note of the index math to go down the diagonal
            while (r < R && c >= 0)
                curr.push_back(mat[r++][c--]);

            // Reverse even numbered diagonals. The article
            // says we have to reverse odd numbered articles
            // but here, the numbering is starting from 0.
            if (d % 2 == 0) reverse(curr.begin(), curr.end());
            
            for (int digit : curr) ans.push_back(digit);
        }

        return ans;
    }
};