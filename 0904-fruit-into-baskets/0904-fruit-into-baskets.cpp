class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        // key : fruit type number, value: quantity of fruits for each type(within max 2 types)
        unordered_map<int, int> basket_2;
        int left = 0, quantity = 0;
        
        for (int right = 0; right < fruits.size(); ++right){
            ++basket_2[fruits[right]];
            
            while (left < right && basket_2.size() > 2){
                --basket_2[fruits[left]];
                if (basket_2[fruits[left]] == 0) basket_2.erase(fruits[left]);
                ++left;
            }
            
            
            quantity = max(quantity, right - left + 1);
        }
        
        return quantity;
    }
};