class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0;
        stack<int> st;

        for (int price : prices) {
            if (!st.empty() && ((st.top() - price) != 1)){
                ans += (long long)(st.size() * (st.size() + 1) >> 1);
                while (!st.empty()) st.pop();
            }
            
            st.push(price);
        }

        if (!st.empty()) ans += (long long)(st.size() * (st.size() + 1) >> 1);

        return ans;
    }
};