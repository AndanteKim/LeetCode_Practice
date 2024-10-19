class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOrVal = 0, n = nums.size();
        vector<int> dp(1 << 17);
        
        // Initialize the empty subset
        dp[0] = 1;
        
        // Iterate through each number in the input array
        for (int num : nums){
            for (int i = maxOrVal; i >= 0; --i){
                // For each existing subset, create a new subset by including
                // the current number
                dp[i | num] += dp[i];
            }
            
            // Update the maximum OR value
            maxOrVal |= num;
        }
        
        return dp[maxOrVal];
    }
};