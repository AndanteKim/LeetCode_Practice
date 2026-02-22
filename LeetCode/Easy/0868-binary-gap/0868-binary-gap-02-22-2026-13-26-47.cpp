class Solution {
public:
    int binaryGap(int n) {
        int prev = -1, ans = 0, i = 0;
        int num = n;

        while (num > 0) {
            if (num % 2) {
                if (prev != -1) ans = max(ans, i - prev);
                prev = i;
            }

            ++i;
            num >>= 1;
        }

        return ans;
    }
};