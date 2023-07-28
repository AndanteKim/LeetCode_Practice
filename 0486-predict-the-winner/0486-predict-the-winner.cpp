class Solution {
private:
    int n;
    int maxDiff(int left, int right, vector<vector<int>>& memo, vector<int>& nums){
        if (left == right) return nums[left];
        if (memo[left][right] != -1) return memo[left][right];
        
        int scoreByLeft = nums[left] - maxDiff(left + 1, right, memo, nums);
        int scoreByRight = nums[right] - maxDiff(left, right - 1, memo, nums);
        return memo[left][right] = max(scoreByLeft, scoreByRight);
    }
    
public:
    bool PredictTheWinner(vector<int>& nums) {
        this -> n = nums.size();
        vector<vector<int>> memo(this -> n, vector<int>(this -> n, -1));
        return maxDiff(0, this -> n - 1, memo, nums) >= 0;
    }
};