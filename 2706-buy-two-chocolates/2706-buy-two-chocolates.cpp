class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int maxPrice = *max_element(prices.begin(), prices.end()), count = 0, ans = money;
        vector<int> countingSort(maxPrice + 1);
        for (int price:prices)
            ++countingSort[price];
        
        for (int price = 0; price <= maxPrice && count < 2 && ans >= 0; ++price){
            while (count < 2 && countingSort[price] > 0){
                ans -= price;
                ++count;
                --countingSort[price];
            }
        }
        
        return count != 2 || ans < 0? money : ans;
    }
};