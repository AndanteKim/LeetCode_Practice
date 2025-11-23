class Solution {
private:
    int n;
    int dp(int i, int mod, vector<vector<int>>& memo, vector<int>& nums) {
        if (i == n) return mod % 3 == 0? 0 : std::numeric_limits<int>::min();

        if (memo[i][mod] != -1) return memo[i][mod];

        int greatestSum = max(nums[i] + dp(i + 1, (mod + nums[i]) % 3, memo, nums), dp(i + 1, mod, memo, nums));
        return memo[i][mod] = greatestSum;
    }

public:
    int maxSumDivThree(vector<int>& nums) {
        this -> n = nums.size();
        vector memo(n, vector<int>(3, -1));

        return dp(0, 0, memo, nums);
    }
};