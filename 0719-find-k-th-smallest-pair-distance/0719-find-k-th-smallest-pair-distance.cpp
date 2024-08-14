class Solution {
private:
    int n;
    
    // Count number of pairs with distance <= maxDist using a moving window
    int countPairsWithMaxDistance(vector<int>& nums, int maxDist){
        int left = 0, count = 0;
        
        for (int right = 0; right < n; ++right){
            // Adjust the left pointer to maintain the window with distances <=
            // maxDist
            while (nums[right] - nums[left] > maxDist)
                ++left;
            
            // Add the number of valid pairs ending at the current right index
            count += right - left;
        }
        
        return count;
    }
    
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        this -> n = nums.size();
        
        // Initialize binary search range
        int low = 0, high = nums.back() - nums[0];
        
        while (low < high){
            int mid = (low + high) >> 1;
            
            // Count pairs with distance <= mid
            int count = countPairsWithMaxDistance(nums, mid);
            
            // Adjust binary search bounds based on count
            if (count < k)
                low = mid + 1;
            else
                high = mid;
        }
        
        return low;
    }
};