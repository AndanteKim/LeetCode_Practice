class Solution {
private:
    bool dp(int i, unordered_map<int, bool>& memo, vector<int>& nums){
        if (memo.find(i) != memo.end()) return memo[i];
        bool ans = false;
        if (i > 0 && nums[i] == nums[i - 1])
            ans |= dp(i - 2, memo, nums);
        if (i > 1 && nums[i] == nums[i - 1] && nums[i - 1] == nums[i - 2])
            ans |= dp(i - 3, memo, nums);
        if (i > 1 && nums[i] == nums[i - 1] + 1 && nums[i] == nums[i - 2] + 2)
            ans |= dp(i - 3, memo, nums);
        return memo[i] = ans;
    }
    
public:
    bool validPartition(vector<int>& nums) {
        unordered_map<int, bool> memo{{-1, true}};
        int n = nums.size();
        
        return dp(n - 1, memo, nums);
    }
};