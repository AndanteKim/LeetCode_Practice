class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int length = nums.size();
        int left = 0, right = length - 1;
        vector<int> result(length, 0);
        for (int i = length-1; i >= 0; --i){
            if (abs(nums[left]) < abs(nums[right])){
                result[i] = nums[right] * nums[right];
                --right;
            }
            else{
                result[i] = nums[left] * nums[left];
                ++left;
            }
        }
        
        return result;
    }
};