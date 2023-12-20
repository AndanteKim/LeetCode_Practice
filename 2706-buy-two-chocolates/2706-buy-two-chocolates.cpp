class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(), prices.end(), [](int a, int b){return a > b;});
        
        int n = prices.size(), change = money - prices[n - 1] - prices[n - 2];
        
        return change < 0? money : change;
    }
};