class Solution {
public:
    int findComplement(int num) {
        // n is a length of num in binary representation
        int n = log2(num) + 1;
        
        // The bitmask has the same length as num and contains only ones 1...1
        int bitmask = (long)(1 << n) - 1;
        
        // Flip all bits
        return static_cast<int>(bitmask ^ num);
    }
};