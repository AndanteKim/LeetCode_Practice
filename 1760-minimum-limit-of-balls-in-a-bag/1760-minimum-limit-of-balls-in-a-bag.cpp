class Solution {
private:
    // Helper function to check if a distribution is possible for a given maxBallsInBag
    bool isPossible(vector<int>& nums, int maxBallsInBag, int maxOperations){
        int totalOperations = 0;
        
        // Iterate through each bag in the array
        for (int num : nums){
            // Calculate the number of operations needed to split this bag
            totalOperations += ceil((double)num / maxBallsInBag) - 1;
            
            // Total operations exceed maxOperations, return false
            if (totalOperations > maxOperations)
                return false;
        }
        
        // We can split the balls within the allowed operations, return true
        return true;
    }
    
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        // Binary search bounds
        int left = 1, right = *max_element(nums.begin(), nums.end());
        
        // Perform binary search to find the optimal maxBallsInBag
        while (left < right){
            int mid = left + ((right - left) >> 1);
            
            // Check if a valid distribution is possible within the current middle value
            if (isPossible(nums, mid, maxOperations))
                right = mid;    // If possible, try a smaller value (shift right to middle)
            else
                left = mid + 1; // If not possible, try a larger value (shift left to middle + 1)
        }
        
        // Return the smallest possible value for maxBallsInBag
        return left;
    }
};