class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // Array to store the count of distinct values encountered
        vector<int> distinctCount(nums.size() + 1, 0);
        int left = 0, currCount = 0, totalCount = 0;
        
        for (int right = 0; right < nums.size(); ++right){
            // Increment the count of the current element in the window
            ++distinctCount[nums[right]];
            
            // If encountering a new distinct element, decrement K
            if (distinctCount[nums[right]] == 1) --k;
            
            // If k becomes negative, adjust the window from the left
            if (k < 0){
                // Move the left pointer until the count of distinct elements
                // becomes valid again
                --distinctCount[nums[left++]];
                ++k;
                currCount = 0;
            }
            
            // If k becomes zero, calculate the subarrays
            if (k == 0){
                // While the count of left remains greater than 1, keep
                // shrinking the window from the left
                while (distinctCount[nums[left]] > 1){
                    --distinctCount[nums[left++]];
                    ++currCount;
                }
                
                // Add the count of subarrays with k distinct elements to the
                // total count
                totalCount += currCount + 1;
            }
        }
        
        return totalCount;
    }
};