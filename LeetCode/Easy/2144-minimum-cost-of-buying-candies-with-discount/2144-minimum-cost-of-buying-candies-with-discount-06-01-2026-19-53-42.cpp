class Solution {
public:
    int minimumCost(vector<int>& cost) {
        if (cost.size() <= 2) return accumulate(cost.begin(), cost.end(), 0);

        int j = 0, n = cost.size(), ans = 0;

        sort(cost.begin(), cost.end(), [](int a, int b) {return a > b;});
        for (int i = 0; i < n - 2; i += 3) {
            ans += cost[i] + cost[i + 1];
            j = i + 3;
        }

        for (int i = j; i < n; ++i) ans += cost[i];

        return ans;
    }
};