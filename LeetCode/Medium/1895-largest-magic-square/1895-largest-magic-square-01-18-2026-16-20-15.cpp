class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector rowSum(m, vector<int>(n)), colSum(m, vector<int>(n));

        // Prefix sum of each row
        for (int i = 0; i < m; ++i) {
            rowSum[i][0] = grid[i][0];
            for (int j = 1; j < n; ++j) {
                rowSum[i][j] = rowSum[i][j - 1] + grid[i][j];
            }
        }

        // Prefix sum of each column
        for (int j = 0; j < n; ++j) {
            colSum[0][j] = grid[0][j];
            for (int i = 1; i < m; ++i) {
                colSum[i][j] = colSum[i - 1][j] + grid[i][j];
            }
        }

        // Enumerate edge lengths from largest to smallest
        for (int edge = min(m, n); edge > 1; --edge) {
            // Enumerate the top-left corner (i, j) of the square
            for (int i = 0; i < m - edge + 1; ++i) {
                for (int j = 0; j < n - edge + 1; ++j) {
                    int stdSum = rowSum[i][j + edge - 1] - (
                        j == 0? 0 : rowSum[i][j - 1]
                    );
                    bool check = true;

                    // Enumerate each row and directly compute the sum using
                    // prefix sums since we've already used the first line as a sample
                    // , we can skip the first line here.
                    for (int ii = i + 1; ii < i + edge; ++ii) {
                        if (stdSum !=
                            rowSum[ii][j + edge - 1] - (
                                j == 0? 0 : rowSum[ii][j - 1]
                            )
                        ) {
                            check = false;
                            break;
                        }
                    }
                    if (!check) continue;
                    
                    // Enumerate each column and directly calculate the sum
                    // using prefix sums
                    for (int jj = j; jj < j + edge; ++jj) {
                        if (stdSum != 
                            colSum[i + edge - 1][jj] - (
                                i == 0? 0 : colSum[i - 1][jj]
                            )
                        ) {
                            check = false;
                            break;
                        }
                    }
                    if (!check) continue;

                    // d1 and d2 represent the sums of the two diagonals
                    // respectively. Note: d denotes diagonal/
                    int d1 = 0, d2 = 0;

                    // Sum directly by traversing without using the prefix sum.
                    for (int k = 0; k < edge; ++k) {
                        d1 += grid[i + k][j + k];
                        d2 += grid[i + k][j + edge - 1 - k];
                    }

                    if (d1 == stdSum && d2 == stdSum) return edge;
                }
            }
        }

        return 1;
    }
};