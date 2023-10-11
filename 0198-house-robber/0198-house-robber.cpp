class Solution {
private:
    int n;
    int dp(int i, vector<int>& nums, vector<int>& memo){
        if (i >= n)
            return 0;
        
        if (memo[i] != -1) return memo[i];
        return memo[i] = max(nums[i] + dp(i + 2, nums, memo), dp(i + 1, nums, memo));
    }
    
public:
    int rob(vector<int>& nums) {
        this -> n = nums.size();
        vector<int> memo(n + 1, -1);
        return dp(0, nums, memo);
    }
};