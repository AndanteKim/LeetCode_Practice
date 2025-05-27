class Solution {
public:
    int differenceOfSums(int n, int m) {
        int k = n / m;
        // num1 - num2 = n(n + 1) / 2 - 2 num2 = n(n + 1) / 2 - k (k + 1) * m
        return (n * (n + 1) >> 1) - k * (k + 1) * m;
    }
};