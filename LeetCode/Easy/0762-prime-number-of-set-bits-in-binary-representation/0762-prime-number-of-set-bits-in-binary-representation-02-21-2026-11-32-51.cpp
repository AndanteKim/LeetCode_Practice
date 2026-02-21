class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0, cnt;

        for (int num = left; num <= right; ++num) {
            cnt = __builtin_popcount(num);
            bool isPrime = true;

            if (cnt <= 1) continue;

            for (int p = 2; p * p <= cnt; ++p) {
                if ((cnt % p) == 0) {
                    isPrime = false;
                    break;
                }
            }

            if (isPrime) ++ans;
        }

        return ans;
    }
};