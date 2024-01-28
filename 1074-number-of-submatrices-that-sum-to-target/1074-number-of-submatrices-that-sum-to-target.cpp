class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> ps(m + 1, vector<int>(n + 1));
        
        // Compute 2D prefix-sum
        for (int i = 1; i <= m; ++i){
            for (int j = 1; j <= n; ++j){
                ps[i][j] = ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
        
        // Reduce 2D problem to 1D one
        // by fixing two rows r1 and r2 and
        // by computing 1D prefix sum for all matrices using [r1...r2] rows
        int count = 0;
        for (int r1 = 1; r1 <= m; ++r1){
            for (int r2 = r1; r2 <= m; ++r2){
                unordered_map<int, int> h;
                h[0] = 1;
                int currSum;
                for (int c = 1; c <= n; ++c){
                    // current 1D prefix sum
                    currSum = ps[r2][c] - ps[r1 - 1][c];
                    
                    // add subarrays which sum up to (curr_sum - target)
                    count += h[currSum - target];
                
                    // Save current prefix sum
                    ++h[currSum];
                }
            }
        }
        
        return count;
    }
};