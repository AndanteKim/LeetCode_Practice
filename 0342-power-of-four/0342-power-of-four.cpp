class Solution {
public:
    bool isPowerOfFour(int n) {
        long long start = 1;
        while (start < n)
            start *= 4;
        return start == n;
    }
};