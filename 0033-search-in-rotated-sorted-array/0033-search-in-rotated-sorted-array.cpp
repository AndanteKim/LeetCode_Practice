class Solution {
    int findRotateIndex(int left, int right, vector<int>& nums){
        if (nums[left] < nums[right]) return 0;
        
        while (left <= right){
            int mid = left + (right - left) / 2;
            
            if (nums[mid] > nums[mid + 1]) return mid + 1;
            else{
                if (nums[mid] < nums[left]) right = mid - 1;
                else left = mid + 1;
            }
        }
        return 0;
    }
    
    int partialSearch(int left, int right, vector<int>& nums, int target){
        while (left <= right){
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) return mid;
            else{
                if (target < nums[mid]) right = mid - 1;
                else left = mid + 1;
            }
        }
        
        return -1;
    }
    
    
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 1){
            return (nums[0] == target)? 0 : -1;
        }
        
        int rotateIndex = findRotateIndex(0, n - 1, nums);
        if (nums[rotateIndex] == target) return rotateIndex;
        if (rotateIndex == 0) return partialSearch(0, n - 1, nums, target);
        if (target < nums[0]) return partialSearch(rotateIndex, n - 1, nums, target);
        return partialSearch(0, rotateIndex, nums, target);
    }
};