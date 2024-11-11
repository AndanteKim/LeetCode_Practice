class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int maxElement = *max_element(nums.begin(), nums.end()), n = nums.size();
        
        // Store the sieve array.
        vector<int> sieves(maxElement + 1, 1);
        sieves[1] = 0;
        
        for (int i = 2; i <= sqrt(maxElement + 1); ++i){
            if (sieves[i]){
                for (int j = i * i; j <= maxElement; j += i)
                    sieves[j] = 0;
            }                                
        }
        
        // Start by storing the currValue as 1, and the initial index as 0.
        int i = 0, currValue = 1;
        
        while (i < n){
            // Store the difference needed to make nums[i] equal to currValue.
            int difference = nums[i] - currValue;
            
            // If difference is less than 0, then nums[i] is already less than currValue.
            // Return false in this case.
            if (difference < 0) return false;
            
            // If the difference is prime or zero, then nums[i] can be made
            // equal to currValue.
            if (sieves[difference] || difference == 0){
                ++i;
                ++currValue;
            }
            else
                // Otherwise, try for the next currValue.
                ++currValue;
        }
        
        return true;
    }
};