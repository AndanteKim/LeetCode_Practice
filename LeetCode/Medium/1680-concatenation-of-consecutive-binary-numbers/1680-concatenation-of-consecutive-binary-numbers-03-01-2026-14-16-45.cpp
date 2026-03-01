class Solution {
public:
    int concatenatedBinary(int n) {
        // length := Bit length of addends
        // ans := long accumulator
        int ans = 0, length = 0, MOD = pow(10, 9) + 7;

        for (int i = 1; i <= n; ++i) {
            // When meeting power of 2, increase the bit length
            if ((i & (i - 1)) == 0) ++length;
            ans = ((long long)ans << length | i) % MOD;
        }

        return ans;
    }
};