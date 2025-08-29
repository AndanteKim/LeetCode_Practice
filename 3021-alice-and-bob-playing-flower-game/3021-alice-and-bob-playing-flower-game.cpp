class Solution {
public:
    long long flowerGame(int n, int m) {
        long long nEven = n >> 1, mEven = m >> 1;
        long long nOdd = n - nEven, mOdd = m - mEven;

        return nEven * mOdd + nOdd * mEven;
    }
};