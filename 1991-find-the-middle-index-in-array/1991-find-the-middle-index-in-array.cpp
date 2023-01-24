class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0), leftSum = 0;
        
        for (int i = 0; i < nums.size(); ++i){
            if (sum - nums[i] == 2 * leftSum) return i;
            leftSum += nums[i];
        }
        
        return -1;
    }
};