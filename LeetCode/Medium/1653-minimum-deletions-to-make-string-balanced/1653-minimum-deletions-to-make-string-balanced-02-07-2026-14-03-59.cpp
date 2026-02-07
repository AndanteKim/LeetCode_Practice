class Solution {
public:
    int minimumDeletions(string s) {
        int ans = 0;
        stack<char> st;

        for (const char& c : s) {
            if (!st.empty() && st.top() == 'b' && c == 'a') {
                st.pop();
                ++ans;
            }
            else st.push(c);
        }

        return ans;
    }
};