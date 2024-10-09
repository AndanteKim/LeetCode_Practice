class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int mismatch = 0;
        
        for (const auto& c : s){
            if (c == '('){
                st.push(c);
                continue;
            }
            else{
                if (!st.empty())
                    st.pop();
                else
                    ++mismatch;
            }
        }
        
        while (!st.empty()){
            ++mismatch;
            st.pop();
        }
        
        return mismatch;
    }
};