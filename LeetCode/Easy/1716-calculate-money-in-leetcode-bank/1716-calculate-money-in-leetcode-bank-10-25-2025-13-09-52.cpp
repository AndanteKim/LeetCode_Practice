class Solution {
public:
    int totalMoney(int n) {
        int ans = 0, start = 1;

        for (int week = 0; week < n / 7; ++week){
            for (int money = start; money < start + 7; ++money)
                ans += money;
            ++start;
        }

        for (int money = start; money < start + n % 7; ++money) ans += money;

        return ans;
    }
};