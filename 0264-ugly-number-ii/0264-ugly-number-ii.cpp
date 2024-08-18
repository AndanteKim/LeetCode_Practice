class Solution {
public:
    int nthUglyNumber(int n) {
        set<long> uglySets;     // Set to store potential ugly numbers
        uglySets.insert(1);     // Start with 1, the first ugly number
        long currUgly = 1;
        
        for (int i = 0; i < n; ++i){
            // Get the smallest number from the set
            currUgly = *uglySets.begin();
            
            // Remove it from the set
            uglySets.erase(currUgly);
            
            // Insert the next potential ugly numbers
            uglySets.insert(currUgly * 2);
            uglySets.insert(currUgly * 3);
            uglySets.insert(currUgly * 5);
        }
        
        return static_cast<int>(currUgly);  // Return the nth ugly number
    }
};