class Solution {
private:
    int n, target;
    int dfs(int idx, int total, vector<int>& nums){
        if (idx == n && total == target) return 1;
        if (idx >= n && total != target) return 0;
        
        int ways = 0;
        total += nums[idx];
        ways += dfs(idx + 1, total, nums);
        total -= nums[idx];
        total -= nums[idx];
        ways += dfs(idx + 1, total, nums);
        
        return ways;
    }
    
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size(), this -> target = target;
        return dfs(0, 0, nums);
    }
};