class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, j = nums.size() - 1, cnt = 0;
        
        while (i <= j){
            if (nums[j] == val){
                --j;
                ++cnt;
                continue;
            }
            else if (nums[i] == val){
                swap(nums[i], nums[j]);
                ++cnt;
                --j;
            }
            ++i;
        }
        
        return nums.size() - cnt;
    }
};