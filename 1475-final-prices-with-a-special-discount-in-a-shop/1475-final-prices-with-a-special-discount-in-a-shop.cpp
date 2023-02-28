class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        stack<int> *st = new stack<int>;
        vector<int> ans(n, 0);
        
        for (int i = 0; i < n; ++i){
            while (!st -> empty() && prices[st -> top()] >= prices[i]){
                int j = st -> top();
                st -> pop();
                ans[j] = prices[j] - prices[i];
            }
            st -> push(i);
        }
        
        while (!st -> empty()){
            int i = st -> top();
            st -> pop();
            ans[i] = prices[i];
        }
        
        return ans;
    }
};