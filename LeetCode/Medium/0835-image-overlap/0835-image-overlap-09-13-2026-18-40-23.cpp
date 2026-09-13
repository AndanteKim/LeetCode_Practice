class Solution {
protected:
    int m;

    int shiftCount(int dy, int dx, vector<vector<int>>& M, vector<vector<int>>& R) {
        int left = 0, right = 0;

        for (int mRow = dy, rRow = 0; mRow < m; ++mRow, ++rRow) {
            for (int mCol = dx, rCol = 0; mCol < m; ++rCol, ++mCol) {
                if (M[mRow][mCol] && M[mRow][mCol] == R[rRow][rCol]) ++left;
                if (M[mRow][rCol] && M[mRow][rCol] == R[rRow][mCol]) ++right;
            }
        }

        return max(left, right);
    }

public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        this -> m = img1.size();
        int ans = 0;
    
        for (int dy = 0; dy < m; ++dy) {
            for (int dx = 0; dx < m; ++dx) {
                ans = max(ans, shiftCount(dy, dx, img1, img2));
                ans = max(ans, shiftCount(dy, dx, img2, img1));
            }
        }

        return ans;
    }
};