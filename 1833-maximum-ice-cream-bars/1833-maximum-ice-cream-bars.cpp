typedef long long ll;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int mx = *max_element(costs.begin(), costs.end());
        vector<int> counting(mx + 1);
        int ans = 0;
        ll total = 0;
        
        for (int cost : costs){
            ++counting[cost];
            ++ans;
            total += cost;
        }
        
        int i = counting.size() - 1;
        
        while (i > 0 && total > coins){
            if (counting[i] == 0) --i;
            else{
                total -= i;
                --ans;
                --counting[i];
            }
        }
        
        return ans;
    }
};