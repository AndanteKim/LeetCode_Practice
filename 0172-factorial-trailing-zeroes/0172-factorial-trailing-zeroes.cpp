class Solution {
public:
    int trailingZeroes(int n) {
        int currentMultiple = 5, zeroCount = 0;
        
        while (n >= currentMultiple){
            zeroCount += n / currentMultiple;
            currentMultiple *= 5;
        }
        
        return zeroCount;
    }
};