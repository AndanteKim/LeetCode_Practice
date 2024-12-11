class Solution {
private:
    int n;
    
    // Helper function to find the largest index where arr[index] <= val
    int findUpperBound(vector<int>& nums, int target){
        int low = 0, high = n - 1, result = 0, mid;
        
        // Perform binary search to find the upper bound
        while (low <= high){
            mid = low + ((high - low) >> 1);
            
            if (nums[mid] <= target){
                result = mid;   // Update the result and move to the right half
                low = mid + 1;
            }
            else{
                high = mid - 1;     // Move to the left half
            }
        }
        
        return result;
    }
    
public:
    int maximumBeauty(vector<int>& nums, int k) {
        this -> n = nums.size();
        sort(nums.begin(), nums.end());
        int maxBeauty = 0, upperBound;
        
        for (int i = 0; i < n; ++i){
            // Find the farthest index where the value is within the range [num, num + 2 * k] 
            upperBound = findUpperBound(nums, nums[i] + 2 * k);
            
            // Update the maximum beauty based on the current range
            maxBeauty = max(maxBeauty, upperBound - i + 1);
        }
        
        return maxBeauty;
    }
};