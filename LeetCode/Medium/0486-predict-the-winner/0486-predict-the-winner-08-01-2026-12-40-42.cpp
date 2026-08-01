class Solution {
private:
    int maxDiff(int left, int right, vector<int>& nums) {
        if (left == right) return nums[left];

        int scoreByLeft = nums[left] - maxDiff(left + 1, right, nums);
        int scoreByRight = nums[right] - maxDiff(left, right - 1, nums);

        return max(scoreByLeft, scoreByRight);
    }

public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();

        return maxDiff(0, n - 1, nums) >= 0;
    }
};