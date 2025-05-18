class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        // For all idx < p0 : nums[idx < p0] = 0
        // curr is an index of elements under consideration
        int curr = 0, p0 = curr;

        // For all idx > p2 : nums[idx > p2] = 2
        int p2 = n - 1;

        while (curr <= p2){
            if (nums[curr] == 0){
                swap(nums[curr++], nums[p0++]);
            }
            else if (nums[curr] == 2){
                swap(nums[curr], nums[p2--]);
            }
            else
                ++curr;
        }
    }
};