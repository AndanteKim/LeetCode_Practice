class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // Find the sum of elements of array
        int total = accumulate(nums.begin(), nums.end(), 0);

        // Base case: If totalSum is odd, it cannot be partitioned into equal sum subset
        if (total % 2 != 0) return false;

        int subsetSum = total >> 1;
        vector<bool> dp(subsetSum + 1, false);
        dp[0] = true;
        
        for (int num : nums){
            for (int j = subsetSum; j >= num; --j){
                dp[j] = dp[j] || dp[j - num];
            }
        }
        return dp[subsetSum];
    }
};