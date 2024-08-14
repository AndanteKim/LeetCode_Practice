class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        // Find the size of nums and the maximum element in the array
        int n = nums.size(), maxElement = *max_element(nums.begin(), nums.end());
        
        // Initialize a bucket array to store counts of each distance
        vector<int> distanceBucket(maxElement + 1);
        
        // Populate the bucket array with counts of each distance
        for (int i = 0; i < n; ++i){
            for (int j = i + 1; j < n; ++j){
                // Compute the distance between nums[i] and nums[j]
                int dist = abs(nums[i] - nums[j]);
                
                // Increment the count for this distance in the bucket
                ++distanceBucket[dist];
            }
        }
        
        // Find the k-th smallest distance
        for (int dist = 0; dist <= maxElement; ++dist){
            // Reduce k by the number of pairs with the current distance
            k -= distanceBucket[dist];
            
            // If k is less than or equal to 0, return the current distance
            if (k <= 0)
                return dist;
        }
        
        // If no distance found as edge cases
        return -1;
    }
};