class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        unordered_map<char, char> matching{{'{','}'}, {'[', ']'}, {'(', ')'}};
        
        for (const char& c: s){
            if (matching.find(c) != matching.end()) st.push(c);
            else{
                if (st.empty()) return false;
                char previous_opening = st.top();
                st.pop();
                if (matching[previous_opening] != c) return false;
            }
        }
        
        return st.empty();
    }
};