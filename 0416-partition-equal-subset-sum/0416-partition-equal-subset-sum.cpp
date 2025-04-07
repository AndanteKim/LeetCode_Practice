class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // Find sum of array elements
        int total = accumulate(nums.begin(), nums.end(), 0);

        // If total_sum is odd, it cannot be partitioned into equal sum subsets
        if (total % 2 != 0) return false;
        int n = nums.size(), subsetSum = total >> 1;

        // construct a dp table of size (n + 1) x (subsetSum + 1)
        vector dp(n + 1, vector<bool>(subsetSum + 1));
        dp[0][0] = true;
        for (int i = 1; i <= n; ++i){
            int curr = nums[i - 1];

            for (int j = 0; j <= subsetSum; ++j){
                if (j < curr)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - curr];
            }
        }

        return dp[n][subsetSum];
    }
};