class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        vector<int> count(100'001);
        int mx = std::numeric_limits<int>::min(), mn = std::numeric_limits<int>::max();

        for (int cost : costs) {
            ++count[cost];
            mx = max(mx, cost);
            mn = min(mn, cost);
        }

        int ans = 0;
        for (int cost = mn; cost <= mx; ++cost){
            if (coins < (long long)cost * count[cost]) {
                ans += coins / cost;
                break;
            }

            ans += count[cost];
            coins -= cost * count[cost];
        }

        return ans;
    }
};