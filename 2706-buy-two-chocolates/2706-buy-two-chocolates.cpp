class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int minimum = min(prices[0], prices[1]), secondMinimum = max(prices[0], prices[1]);
        
        for (int i = 2; i < prices.size(); ++i){
            if (prices[i] < minimum){
                secondMinimum = minimum;
                minimum = prices[i];
            }
            else if (prices[i] < secondMinimum)
                secondMinimum = prices[i];
        }
        
        return (minimum + secondMinimum <= money)? money - (minimum + secondMinimum) : money;
    }
};