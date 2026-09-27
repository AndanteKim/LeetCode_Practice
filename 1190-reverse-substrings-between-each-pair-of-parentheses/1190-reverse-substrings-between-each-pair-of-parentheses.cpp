class Solution {
public:
    string reverseParentheses(string s) {
        string ans = "";

        for (const char& c : s) {
            if (c == ')') {
                string curr = "";
                while (!ans.empty() && ans.back() != '(') {
                    curr.push_back(ans.back());
                    ans.pop_back();
                }
                ans.pop_back();

                for (const char& c : curr) ans.push_back(c);
            }
            else ans.push_back(c);
        }

        return ans;
    }
};