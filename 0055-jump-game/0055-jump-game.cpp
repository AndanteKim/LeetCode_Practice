class Solution {
private:
    int good = 1, bad = 0, unknown = -1, n;
    bool canJumpFromPosition(int i, vector<int>& memo, vector<int>& nums){
        if (memo[i] != unknown){
            return memo[i] == good? true : false;
        }
        
        int furthest = min(n - 1, nums[i] + i);
        for (int next = i + 1; next <= furthest; ++next){
            if (canJumpFromPosition(next, memo, nums)){
                memo[i] = good;
                return true;
            }
        }
        
        memo[i] = bad;
        return false;
    }
    
public:
    bool canJump(vector<int>& nums) {
        n = nums.size();
        vector<int> memo(n, unknown);
        memo[n - 1] = good;
        
        return canJumpFromPosition(0, memo, nums);
    }
};