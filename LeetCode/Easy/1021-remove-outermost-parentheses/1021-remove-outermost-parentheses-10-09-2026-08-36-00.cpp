class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int level = 0;

        for (const char& c : s) {
            if (c == ')') --level;

            if (level > 0) ans.push_back(c);

            if (c == '(') ++level;
        }

        return ans;
    }
};