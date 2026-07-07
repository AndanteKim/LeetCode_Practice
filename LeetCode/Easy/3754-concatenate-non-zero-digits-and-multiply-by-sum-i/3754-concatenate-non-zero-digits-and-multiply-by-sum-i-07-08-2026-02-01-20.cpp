class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0, sum = 0;
        int digit = 0;

        while (n > 0) {
            int d = n % 10;
            if (d > 0) {
                x += d * (long long)pow(10, digit++);
                sum += d;
            }
            n /= 10;
        }

        return x * sum;
    }
};