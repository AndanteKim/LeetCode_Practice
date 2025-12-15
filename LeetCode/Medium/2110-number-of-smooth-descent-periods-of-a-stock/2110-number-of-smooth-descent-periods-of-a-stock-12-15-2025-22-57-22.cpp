class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 1;
        int n = prices.size(), prev = 1;

        for (int i = 1; i < n; ++i) {
            if (prices[i] == prices[i - 1] - 1) ++prev;
            else prev = 1;
            ans += prev;
        }

        return ans;
    }
};