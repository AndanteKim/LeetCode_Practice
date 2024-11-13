class Solution {
private:
    // Calculate the number of pairs with sum less than 'value'.
    long long boundSearch(vector<int>& nums, int target){
        int left = 0, right = nums.size() - 1;
        long long ans = 0;
        
        while (left < right){
            int sum = nums[left] + nums[right];
            // If sum is less than value, add the size of window to result and move to the next index.
            if (sum < target){
                ans += right - left++;
            }
            else
                // Otherwise, shift the right pointer backwards, until we get a valid window.
                --right;
        }
        
        return ans;
    }
    
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        return boundSearch(nums, upper + 1) - boundSearch(nums, lower);
    }
};