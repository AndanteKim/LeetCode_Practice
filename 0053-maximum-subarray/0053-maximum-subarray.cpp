class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        // Kadane's algorithm
        int best_sum = nums[0], current_sum = 0;
        
        for (const auto num : nums){
            current_sum = max(0, current_sum) + num;
            best_sum = max(current_sum, best_sum);
        }
        return best_sum;
    }
};