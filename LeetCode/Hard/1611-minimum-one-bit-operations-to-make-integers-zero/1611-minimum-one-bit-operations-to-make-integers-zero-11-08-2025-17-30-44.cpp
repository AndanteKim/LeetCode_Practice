class Solution {
public:
    int minimumOneBitOperations(int n) {
        if (n == 0) return 0;
        
        int curr = 1, k = 0;
        while (2 * curr <= n) {
            curr <<= 1;
            ++k;
        }

        return pow(2, k + 1) - 1 - minimumOneBitOperations(n ^ curr);
    }
};