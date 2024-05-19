class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        vector dp(n + 1, vector<long long> (2, 0));
        // Base case
        dp[n][1] = 0, dp[n][0] = LLONG_MIN;
        
        for (int i = n - 1; i >= 0; --i){
            for (int isEven = 0; isEven < 2; ++isEven){
                // Case 1: We performed an operation on this element
                long long xorDone = (nums[i] ^ k) + dp[i + 1][isEven ^ 1];
                
                // Case 2: We don't performed an operation on this element
                long long noXorDone = nums[i] + dp[i + 1][isEven];
                dp[i][isEven] = max(xorDone, noXorDone);
            }
        }
        
        return dp[0][1];
    }
};