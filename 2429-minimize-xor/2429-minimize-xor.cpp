class Solution {
public:
    int minimizeXor(int num1, int num2) {
        // Initialize result to num1. We'll modify result.
        int res = num1;
        
        int targetSetBitsCount = __builtin_popcount(num2), setBitsCount = __builtin_popcount(num1);
        
        // Start with the least significant bit (bit 0).
        int currentBit = 0;

        // Add bits to result if it has fewer set bits than the target.
        while (setBitsCount < targetSetBitsCount){
            // If the current bit in result is not set (0), set it to 1.
            if (!isSet(res, currentBit)){
                setBit(res, currentBit);
                ++setBitsCount;
            }

            // Move to the next bit.
            ++currentBit;
        }

        // Remove bits from result if it has more set bits than the target.
        while (setBitsCount > targetSetBitsCount){
            // If the current bit in result is set (1), unset it (make it 0).
            if (isSet(res, currentBit)){
                unsetBit(res, currentBit);
                --setBitsCount;
            }

            // Move to the next bit.
            ++currentBit;
        }
        
        return res;
    }

private:
    // Helper function to check if the given bit position in x is set (1).
    bool isSet(int x, int bit){
        return (x & (1 << bit)) != 0;
    }

    // Helper function to set the given bit position in x to 1.
    void setBit(int &x, int bit){
        x |= (1 << bit);
    }

    // Helper function to unset the given bit position in x (set it to 0).
    void unsetBit(int &x, int bit){
        x &= ~(1 << bit);
    }
};