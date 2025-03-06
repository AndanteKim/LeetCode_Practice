class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        long long total = n * n, sum = 0, sqrSum = 0;

        // Calculate actual sum and squared sum from grid
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                sum += grid[i][j];
                sqrSum += static_cast<long long>(grid[i][j]) * grid[i][j];
            }
        }

        // Calculate differences from expected sums
        // Expected sum: n(n + 1)/2, Expected square sum: n(n + 1)(2n + 1) / 6
        long long sumDiff = sum - (total * (total + 1) >> 1);
        long long sqrDiff = sqrSum - (total * (total + 1) * (2 * total + 1) / 6);

        // Using math: If x is repeated and y is missing
        // sumDiff = x - y
        // sqrDiff = x^2 - y^2
        int repeat = (sqrDiff / sumDiff + sumDiff) >> 1;
        int missing = (sqrDiff / sumDiff - sumDiff) >> 1;

        return {repeat, missing};
    }
};