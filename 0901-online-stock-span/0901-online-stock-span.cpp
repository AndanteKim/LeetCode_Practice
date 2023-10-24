class StockSpanner {
public:
    stack<pair<int, int>> st;
    StockSpanner() {
        st = stack<pair<int, int>>();
    }
    
    int next(int price) {
        int ans = 1;
        while (!st.empty() && st.top().second <= price){
            ans += st.top().first;
            st.pop();
        }
        
        st.push({ans, price});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */