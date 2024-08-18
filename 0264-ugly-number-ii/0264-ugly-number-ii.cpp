class Solution {
public:
    int nthUglyNumber(int n) {
        // DP arrays to store the ugly numbers
        vector<int> uglyNumbers(n);
        
        // The first ugly number is 1
        uglyNumbers[0] = 1;
        
        // 3 Pointers to for the multiples of 2, 3, 5
        int indexOf2 = 0, indexOf3 = 0, indexOf5 = 0;
        int nextMultipleOf2 = 2, nextMultipleOf3 = 3, nextMultipleOf5 = 5;
        
        // Generate ugly numbers until we reach the nth one
        for (int i = 1; i < n; ++i){
            // Find the next ugly number as the minimum of the next multiples
            int nextUglyNumber = min(nextMultipleOf2, min(nextMultipleOf3, nextMultipleOf5));
            uglyNumbers[i] = nextUglyNumber;
            
            // Update the corresponding pointer and next multiple
            if (nextUglyNumber == nextMultipleOf2)
                nextMultipleOf2 = uglyNumbers[++indexOf2] * 2;
            
            if (nextUglyNumber == nextMultipleOf3)
                nextMultipleOf3 = uglyNumbers[++indexOf3] * 3;
            
            if (nextUglyNumber == nextMultipleOf5)
                nextMultipleOf5 = uglyNumbers[++indexOf5] * 5;
            
        }
        
        // Return the nth ugly number
        return uglyNumbers[n - 1];
    }
};