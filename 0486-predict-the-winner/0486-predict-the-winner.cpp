class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; ++i) dp[i][i] = nums[i];
        
        for (int diff = 1; diff < n; ++diff){
            for (int left = 0; left < n - diff; ++left){
                int right = left + diff;
                dp[left][right] = max(nums[left] - dp[left + 1][right], nums[right] - dp[left][right - 1]);
            }
        }
        
        return dp[0][n - 1] >= 0;
    }
};