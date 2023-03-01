class Solution {
    vector<int> mergesort(vector<int>& nums){
        if (nums.size() > 1){
            int mid = nums.size() / 2;
            vector<int> Left = {nums.begin(), nums.begin() + mid}; 
            vector<int> Right = {nums.begin() + mid, nums.end()};
            mergesort(Left);
            mergesort(Right);
            
            int i = 0, j = 0, k = 0;
            while (i < Left.size() && j < Right.size()){
                if (Left[i] <= Right[j]){
                    nums[k] = Left[i];
                    ++i;
                }
                else{
                    nums[k] = Right[j];
                    ++j;
                }
                ++k;
            }
            
            while (i < Left.size()){
                nums[k] = Left[i];
                ++i;
                ++k;
            }
            
            while (j < Right.size()){
                nums[k] = Right[j];
                ++j;
                ++k;
            }
            
            return nums;
        }
        return {};
    }
    
public:
    vector<int> sortArray(vector<int>& nums) {
        if (nums.size() <= 1) return nums;
        return mergesort(nums);
    }
};