class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int ans = 0, curr = 0;
        
        for (char& c:s){
            if (c == '('){
                st.push('(');
                ++curr;
            }
            else if (c == ')'){
                st.pop();
                ans = max(ans, curr);
                --curr;
            }
        }
        
        return st.empty()? ans:0;
    }
};