class Solution {
private:
    int m, n;
    int findSquare(int x1, int y1, int x2, int y2, vector<vector<int>>& P) {
        return P[x2][y2] - P[x2][y1 - 1] - P[x1 - 1][y2] + P[x1 - 1][y1 - 1];
    }

public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        m = mat.size(), n = mat[0].size();

        vector P(m + 1, vector<int>(n + 1));

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                P[i][j] = (
                    P[i - 1][j]
                    + P[i][j - 1]
                    - P[i - 1][j - 1]
                    + mat[i - 1][j - 1]               
                );
            }
        }    
        
        int l = 1, r = min(m, n), ans = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            bool find = false;

            for (int i = 1; i < m - mid + 2; ++i) {
                for (int j = 1; j < n - mid + 2; ++j) {
                    if (findSquare(i, j, i + mid - 1, j + mid - 1, P) <= threshold) {
                        find = true;
                    }
                }
            }

            if (find) {
                ans = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }

        return ans;
    }
};