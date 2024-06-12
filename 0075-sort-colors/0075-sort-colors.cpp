class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        // For all idx > p0, nums[idx > p0] = 0
        // For all idx < p2, nums[idx < p2] = 2
        // curr := an index of elements under consideration
        int p0 = 0, curr = 0, p2 = nums.size() - 1;
        
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