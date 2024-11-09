typedef long long ll;

class Solution {
public:
    long long minEnd(int n, int x) {
        // Reduce n by 1 to exclude x from the iteration
        --n;
        
        // Step 1: Initialize vectors to hold the binary representation of x and n - 1
        vector<int> binaryX(64), binaryN(64);   // Binary representation of x and n - 1
        
        // Convert x, n - 1 to long long for 64-bit manipulation
        ll longX = x, longN = n;
        int bit;
        
        // Step 2: Build the binary representations of x and n - 1
        for (int i = 0; i < 64; ++i){
            bit = (longX >> i) & 1;     // Extract i-th bit of x
            binaryX[i] = bit;
            
            bit = (longN >> i) & 1;     // Extract i-th bit of n - 1
            binaryN[i] = bit;
        }
        
        int posX = 0, posN = 0;
        
        // Step 3: Combine binary representation of x and n - 1
        while (posX < 63){
            // Traverse binaryX until we find a 0 bit
            while (binaryX[posX] && posX < 63){
                ++posX;
            }
            
            // Copy bits from binaryN (n - 1) into binaryX (x) starting from the first 0
            binaryX[posX++] = binaryN[posN++];
        }
        
        // Step 4: Rebuild the final result from the combined binary representation
        ll ans = 0;
        for (int i = 0; i < 64; ++i){
            if (binaryX[i])
                // Convert binary bit to decimal value
                ans += pow(2, i);
        }
        
        return ans;
    }
};