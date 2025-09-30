class Solution {
public:
    bool canDivideIntoSubsequences(vector<int>& nums, int k) {
        int pre = nums[0], cnt = 0;

        for (int num : nums){
            if (pre == num) ++cnt;
            else{
                pre = num;
                cnt = 1;
            }

            if (cnt * k > nums.size()) return false;
        }

        return true;
    }
};