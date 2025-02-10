class Solution {
public:
    string clearDigits(string s) {
        deque<char> st;

        for (const char& c : s){
            if (48 <= c && c <= 57){
                if (!st.empty()) st.pop_back();
            }
            else
                st.push_back(c);
        }

        string ans = "";
        while (!st.empty()){
            ans.push_back(st.front()); st.pop_front();
        }

        return ans;
    }
};