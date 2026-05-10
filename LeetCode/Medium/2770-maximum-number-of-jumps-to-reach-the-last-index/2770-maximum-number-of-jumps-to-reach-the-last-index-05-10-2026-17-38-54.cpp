class Solution {
private:
    int target, n;

    int dp(int i, vector<int>& nums, vector<int>& memo) {
        if (i == n - 1) return 0;

        if (memo[i] != -1) return memo[i];
        
        int maxJump = std::numeric_limits<int>::min();
        for (int j = i + 1; j < n; ++j) {
            if (abs(nums[j] - nums[i]) <= target) {
                maxJump = max(maxJump, 1 + dp(j, nums, memo));
            }
        }

        return memo[i] = maxJump;
    }

public:
    int maximumJumps(vector<int>& nums, int target) {
        this -> target = target;
        this -> n = nums.size();
        vector<int> memo(n, -1);
        int ans = dp(0, nums, memo);
        return ans < 0? -1 : ans;     
    }
};