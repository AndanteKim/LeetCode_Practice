class Solution {
private:
    bool isBinarySearchHelpful(vector<int>& nums, int start, int element){
        return nums[start] != element;
    }
    
    bool existsInFirst(vector<int>& nums, int start, int element){
        return nums[start] <= element;
    }
    
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;
        
        while (left <= right){
            int mid = left + ((right - left) >> 1);
            if (nums[mid] == target) return true;
            if (!isBinarySearchHelpful(nums, left, nums[mid])){
                ++left;
                continue;
            }
            
            bool pivotArray = existsInFirst(nums, left, nums[mid]);
            bool targetArray = existsInFirst(nums, left, target);
            
            if (pivotArray ^ targetArray){
                if (pivotArray) left = mid + 1;
                else right = mid - 1;
            }
            else{
                if (nums[mid] < target) left = mid + 1;
                else right = mid - 1;
            }
        }
        
        return false;
    }
};