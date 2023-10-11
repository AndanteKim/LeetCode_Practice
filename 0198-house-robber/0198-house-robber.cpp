class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1)
            return nums[0];
        int robNextMinusOne = 0, robNext = nums[0];
        
        for (int i = 1; i < n; ++i){
            int curr = max(robNext, robNextMinusOne + nums[i]);
            robNextMinusOne = robNext;
            robNext = curr;
        }
        
        return robNext;
    }
};