class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxVal = 0;
        vector<int> dp(1 << 17);

        // Initialize the empty subset
        dp[0] = 1;

        // Iterate through each number in the input array
        for (int num : nums){
            for (int i = maxVal; i >= 0; --i){
                // For each existing subset, create a new subset by including the current number
                dp[i | num] += dp[i];
            }
            
            // Update the maximum OR value
            maxVal |= num;
        }

        return dp[maxVal];
    }
};