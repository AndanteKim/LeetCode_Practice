class Solution {
public:
    int totalMoney(int n) {
        int ans = 0, monday = 1;

        while (n > 0){
            for (int day = 0; day < min(n, 7); ++day) ans += day + monday;
            n -= 7;
            ++monday;
        }

        return ans;
    }
};