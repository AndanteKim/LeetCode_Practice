class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size(), j;
        stack<int> st;
        vector<int> ans(n, 0);
        
        for (int i = 0; i < n; ++i){
            while ((!st.empty()) && (temperatures[st.top()] < temperatures[i])){
                j = st.top();
                st.pop();
                ans[j] = i - j;
            }
            st.push(i);
        }
        return ans;
    }
};