class Solution {
private:
    bool isPrime(int x){
        for (int i = 2; i <= sqrt(x); ++i){
            if (x % i == 0) return false;
        }
        
        return true;
    }
    
public:
    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size(), maxElement = *max_element(nums.begin(), nums.end());
        
        // Store the previousPrime array.
        vector<int> previousPrime(maxElement + 1);
        
        for (int i = 2; i <= maxElement; ++i){
            if (isPrime(i))
                previousPrime[i] = i;
            else
                previousPrime[i] = previousPrime[i - 1];
        }
        
        int bound;
        for (int i = 0; i < n; ++i){
            // In case of first index, we need to find the largest prime less than nums[0].
            if (i == 0) bound = nums[i];
            else
                // Otherwise, we need to find the largest prime, that makes the
                // current element closest to the previous element.
                bound = nums[i] - nums[i - 1];
            
            // If the bound is less than or equal to 0, then the array cannot be 
            // made strictly increasing.
            if (bound <= 0) return false;
            
            // Find the largest prime less than bound.
            int largestPrime = previousPrime[bound - 1];
            
            // Subtract this value from nums[i].
            nums[i] -= largestPrime;
        }
        
        return true;
    }
};