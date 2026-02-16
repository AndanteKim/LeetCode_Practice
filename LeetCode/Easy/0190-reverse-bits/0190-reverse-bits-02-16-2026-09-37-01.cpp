class Solution {
public:
    int reverseBits(int n) {
        int ans = 0, power = 31;

        while (n > 0) {
            ans += (n & 1) * pow(2, power--);
            n >>= 1;
        }

        return ans;
    }
};