class Solution {
public:
    int bitwiseComplement(int n) {
        // Base case
        if (n == 0) return 1;
        
        int ans = 0, i = 0;
        while (n > 0) {
            ans += (1 << i++) * ((n % 2) ^ 1);
            n >>= 1;
        }
        
        return ans;
    }
};