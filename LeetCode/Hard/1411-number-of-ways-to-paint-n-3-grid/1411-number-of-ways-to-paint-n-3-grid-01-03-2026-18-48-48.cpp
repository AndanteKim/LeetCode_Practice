class Solution {
public:
    int numOfWays(int n) {
        const int mod = 1'000'000'007;
        long A = 6, B = 6;

        for (int i = 2; i <= n; ++i) {
            long prevA = A, prevB = B;
            A = (3 * prevA + 2 * prevB) % mod;
            B = (2 * prevA + 2 * prevB) % mod;
        }

        return static_cast<int>((A + B) % mod);
    }
};