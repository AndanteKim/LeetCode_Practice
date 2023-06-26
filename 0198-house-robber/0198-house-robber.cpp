class Solution {
private:
    int robFrom(int start, vector<int>& nums, unordered_map<int, int>& memo){
        if (start >= nums.size()) return 0;
        if (memo.find(start) != memo.end()) return memo[start];
        
        int ans = max(robFrom(start + 1, nums, memo), robFrom(start + 2, nums, memo) + nums[start]);
        return memo[start] = ans;
    }
    
public:
    int rob(vector<int>& nums) {
        unordered_map<int, int> memo;
        return robFrom(0, nums, memo);
    }
};