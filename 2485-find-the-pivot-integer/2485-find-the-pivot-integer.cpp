class Solution {
public:
    int pivotInteger(int n) {
        // Initialize left and right pointers for binary search
        int left = 1, right = n;
        
        // Calculate the total sum of the sequence.
        int sum = n * (n + 1) >> 1;
        
        // Binary search for the pivot point
        while (left < right){
            // Calculate the mid-point
            int mid = (left + ((right - left) >> 1));
            
            // Check if the difference between the square of mid and the total sum is
            // negative
            if ((mid * mid) - sum < 0)
                left = mid + 1;
            else
                right = mid; // Adjust the right bound if sum is equal or greater.
        }
        
        // Check if the square of the left pointer minus the total sum is zero.
        return (left * left - sum == 0)? left: -1; 
    }
};