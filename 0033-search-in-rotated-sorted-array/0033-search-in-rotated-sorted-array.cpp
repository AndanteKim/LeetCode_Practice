class Solution {
private:
    int binarySearch(int left, int right, int target, vector<int>& nums){
        while (left <= right){
            int mid = left + ((right - left) >> 1);
            
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        
        return -1;
    }
    
public:
    int search(vector<int>& nums, int target) {
        int left = 0, n = nums.size();
        int right = n - 1;
        while (left <= right){
            int mid = left + ((right - left) >> 1);
            if (nums[mid] > nums.back()) left = mid + 1;
            else right = mid - 1;
        }
        
        int ans = binarySearch(0, left - 1, target, nums);
        
        return ans != -1? ans : binarySearch(left, n - 1, target, nums);
    }
};