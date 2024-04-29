class Solution {
public:
    long long maxNumber(long long n) {
        return pow(2, int(log2(n))) - 1;
    }
};