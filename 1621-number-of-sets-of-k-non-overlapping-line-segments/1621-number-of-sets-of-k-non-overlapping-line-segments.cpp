class Solution {
private:
    const int MOD = 1'000'000'007;
    long long quickPow(long long a, long long e) {
        long long res = 1;
        while (e > 0) {
            if (e & 1) res = res * a % MOD;
            a = a * a % MOD;
            e >>= 1;
        }

        return res;
    }

public:
    int numberOfSets(int n, int k) {
        int m = 2 * k;
        long long numerator = 1, denominator = 1;

        for (int i = 1; i <= m; ++i) {
            numerator = numerator * (n + k - i) % MOD;
            denominator = denominator * i % MOD;
        }

        return numerator * quickPow(denominator, MOD - 2) % MOD;
    }
};