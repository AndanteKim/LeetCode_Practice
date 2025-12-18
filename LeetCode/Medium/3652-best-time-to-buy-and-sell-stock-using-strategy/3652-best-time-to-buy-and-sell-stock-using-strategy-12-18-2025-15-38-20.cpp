typedef long long ll;

class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        vector<ll> profitSum(n + 1, 0), priceSum(n + 1, 0);

        for (int i = 0; i < n; ++i){
            profitSum[i + 1] = profitSum[i] + prices[i] * strategy[i];
            priceSum[i + 1] = priceSum[i] + prices[i];
        }
        
        ll ans = profitSum[n];
        ll leftProfit, changeProfit, rightProfit;
        for (int i = k - 1; i < n; ++i) {
            leftProfit = profitSum[i - k + 1];
            changeProfit = priceSum[i + 1] - priceSum[i - (k >> 1) + 1];
            rightProfit = profitSum[n] - profitSum[i + 1];

            ans = max(ans, leftProfit + changeProfit + rightProfit);
        }

        return ans;
    }
};