class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        
        for (const char &c : s){
            if (st.empty() || c != st.top()) st.push(c);
            else if (c == st.top()) st.pop();
        }
        string ans = "";
        
        while (!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};