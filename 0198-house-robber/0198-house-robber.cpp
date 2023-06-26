class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(), robPlusOne = 0, current = 0;
        int robNext = nums[n - 1];
        
        for (int i = n - 2; i >= 0; --i){
            current = max(robPlusOne + nums[i], robNext);
            robPlusOne = robNext;
            robNext = current;
        }
        return robNext;
    }
};