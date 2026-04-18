class Solution {
private:
    int reverseNum(int x) {
        int y = 0;

        while (x > 0) {
            y = y * 10 + x % 10;
            x /= 10;
        }

        return y;
    }

public:
    int mirrorDistance(int n) {
        return abs(n - reverseNum(n));
    }
};