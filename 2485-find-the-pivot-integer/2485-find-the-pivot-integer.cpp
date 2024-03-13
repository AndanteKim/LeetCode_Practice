class Solution {
public:
    int pivotInteger(int n) {
        int leftValue = 1, rightValue = n;
        long leftSum = leftValue, rightSum = rightValue;
        
        if (n == 1) return n;
        
        // Iterate until the pointers meet
        while (leftValue < rightValue){
            // Adjust sums and pointers based on comparison
            if (leftSum < rightSum){
                leftSum += leftValue + 1;
                ++leftValue;
            }
            else{
                rightSum += rightValue - 1;
                --rightValue;
            }
            
            // Check for pivot condition
            if (leftSum == rightSum && leftValue + 1 == rightValue - 1)
                return leftValue + 1;
        }
        
        return -1; // Return -1 if no pivot is found
    }
};