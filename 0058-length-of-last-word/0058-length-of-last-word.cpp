class Solution {
public:
    int lengthOfLastWord(string s) {
        stack<string> st;
        stringstream ss(s);
        string word;
        
        while (ss >> word){
            st.push(word);
        }
        
        return st.top().size();
    }
};