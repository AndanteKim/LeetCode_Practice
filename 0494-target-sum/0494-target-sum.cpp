class Solution {
private:
    int n, target, total;
    int calculate(vector<int>& nums, int idx, int sum, vector<vector<int>>& memo){
        if (idx == n){
            if (sum == target) return 1;
            return 0;
        }
        
        if (memo[idx][sum + total] != INT_MIN) return memo[idx][sum + total];
        int add = calculate(nums, idx + 1, sum + nums[idx], memo);
        int subtract = calculate(nums, idx + 1, sum - nums[idx], memo);
        return memo[idx][sum + total] = add + subtract;
    }
    
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        this -> n = nums.size(), this -> total = accumulate(nums.begin(), nums.end(), 0), this -> target = target;
        vector<vector<int>> memo(this -> n, vector<int>(2 * this -> total + 1, INT_MIN));
        return calculate(nums, 0, 0, memo);
    }
};