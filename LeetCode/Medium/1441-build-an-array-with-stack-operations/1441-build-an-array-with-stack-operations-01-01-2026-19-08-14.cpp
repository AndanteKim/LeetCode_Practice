class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        stack<int> st;
        int pt = 0;

        for (int i = 1; i <= n; ++i) {

            if (i == target[pt]){
                while (!st.empty() && st.top() != target[max(0, pt - 1)]){
                    st.pop();
                    ans.push_back("Pop");
                }
                ++pt;
            }

            st.push(i);
            ans.push_back("Push");
            
            if (pt == target.size()) break;
        }

        return ans;
    }
};