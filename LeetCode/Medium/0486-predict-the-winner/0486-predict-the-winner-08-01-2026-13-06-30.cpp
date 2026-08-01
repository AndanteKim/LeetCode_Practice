class Solution {
private:
    int maxDiff(int left, int right, vector<int>& nums, vector<vector<int>>& memo) {
        if (left == right) return nums[left];
    
        if (memo[left][right] != -1) return memo[left][right];

        int scoreByLeft = nums[left] - maxDiff(left + 1, right, nums, memo);
        int scoreByRight = nums[right] - maxDiff(left, right - 1, nums, memo);

        return memo[left][right] = max(scoreByLeft, scoreByRight);
    }

public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector memo(n, vector<int>(n, -1));

        return maxDiff(0, n - 1, nums, memo) >= 0; 
    }
};