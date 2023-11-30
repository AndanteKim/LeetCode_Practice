class Solution {
public:
    int minimumOneBitOperations(int n) {
        int ans = 0, k = 0, mask = 1;
        
        while (mask <= n){
            if (n & mask)
                ans = pow(2, k + 1) - 1 - ans;
            mask <<= 1;
            ++k;
        }
        
        return ans;
    }
};