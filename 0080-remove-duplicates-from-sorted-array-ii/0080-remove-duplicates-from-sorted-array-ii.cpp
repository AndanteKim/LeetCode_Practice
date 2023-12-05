class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 1, count = 1;
        
        while (i < nums.size()){
            if (nums[i - 1] == nums[i]){
                ++count;
                if (count > 2){
                    nums.erase(nums.begin() + i);
                    --i;
                }
            }
            else{
                count = 1;
            }
            
            ++i;
        }
        
        return nums.size();
    }
};