class Solution {
public:
    int findBestSubarray(vector<int> &nums, int left, int right){
        
        if (left > right) return numeric_limits<int>::min();
        
        int mid = (left + right) >> 1;
        int curr = 0, best_left_sum = 0, best_right_sum = 0;
        
        for (int i = mid - 1; i >= left; --i){
            curr += nums[i];
            best_left_sum = max(best_left_sum, curr);
        }
        
        curr = 0;
        
        for (int i = mid + 1; i <= right; ++i){
            curr += nums[i];
            best_right_sum = max(best_right_sum, curr);
        }
        
        int best_combined_sum = nums[mid] + best_left_sum + best_right_sum;
        
        int left_half = findBestSubarray(nums, left, mid - 1);
        int right_half = findBestSubarray(nums, mid + 1, right);
        
        return max(best_combined_sum, max(left_half, right_half));
    }
    
    int maxSubArray(vector<int>& nums) {
        return findBestSubarray(nums, 0, nums.size()-1);
    }
};