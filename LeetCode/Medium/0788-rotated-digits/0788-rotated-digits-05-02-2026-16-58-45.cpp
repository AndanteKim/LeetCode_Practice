class Solution {
public:
    int rotatedDigits(int n) {
        int ans = 0;
        std::function<bool(int, bool)> check = [&](int num, bool isGood) {
            if (num == 0) return isGood;

            int digit = num % 10;
            if (digit == 3 || digit == 4 || digit == 7) return false;

            if (digit == 2 || digit == 5 || digit == 6 || digit == 9) return check(num / 10, true);
        
            return check(num / 10, isGood);
        };

        for (int i = 1; i <= n; ++i) {
            if (check(i, false))
                ++ans;
        }

        return ans;
    }
};