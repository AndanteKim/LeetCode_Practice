class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[n - 1] = 1;
        
        for (int i = n - 2; i >= 0; --i){
            int furthest = min(n - 1, nums[i] + i);
            for (int nxt = i + 1; nxt <= furthest; ++nxt){
                if (dp[nxt] == 1){
                    dp[i] = 1;
                    break;
                }
            }
        }
        
        return dp[0] == 1;
    }
};