typedef long long ll;

class Solution {
public:
    long long maximumBooks(vector<int>& books) {
        int n = books.size();
        vector<ll> dp(n);
        stack<ll> st;

        auto calSum = [&](int l, int r) {
            int cnt = min(books[r], r - l + 1);
            return ((ll)(2 * books[r] - (cnt - 1)) * cnt) >> 1;
        };

        for (int i = 0; i < n; ++i) {
            while (!st.empty() && books[st.top()] - st.top() >= books[i] - i) st.pop();

            if (st.empty()) dp[i] = calSum(0, i);
            else {
                int j = st.top();
                dp[i] = dp[j] + calSum(j + 1, i);
            } 

            st.push(i);
        } 



        return *max_element(dp.begin(), dp.end());
    }
};