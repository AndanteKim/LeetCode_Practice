class Solution {
private:
    int n, target;
    int backtrack(vector<vector<int>>& dp, vector<int>& nums, int curr, int idx){
        if (idx >= n || curr > target) return 0;
        if (curr == target) return 1;
        if (dp[curr][idx] != -1) return dp[curr][idx];
        int ways = 0;
        for (int i = 0; i < n; ++i){
            ways += backtrack(dp, nums, curr + nums[i], i);
        }
        
        return dp[curr][idx] = ways;
    }
    
public:
    int combinationSum4(vector<int>& nums, int target) {
        this -> n = nums.size();
        this -> target = target;
        vector<vector<int>> dp(target + 1, vector<int>(n + 1, -1));
        
        return backtrack(dp, nums, 0, 0);
    }
};