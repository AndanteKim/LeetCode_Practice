class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxSum = 0, currentSubarraySum = nums[0];

        // Loop through the list starting from the second element
        for (int i = 1; i < nums.size(); ++i){
            if (nums[i] <= nums[i - 1]){
                // If the current element isn't greater than the previous one,
                // update maxSum
                maxSum = max(maxSum, currentSubarraySum);
                // Reset the sum for the next ascending subarray
                currentSubarraySum = 0;
            }
            currentSubarraySum += nums[i];
        }

        // Final check after the loop ends to account for the last ascending subarray
        return max(maxSum, currentSubarraySum);
    }
};