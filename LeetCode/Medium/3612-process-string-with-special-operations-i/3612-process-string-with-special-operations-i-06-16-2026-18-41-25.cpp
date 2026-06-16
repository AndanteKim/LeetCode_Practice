class Solution {
public:
    string processStr(string s) {
        string curr = "";

        for (const char& c : s) {
            if (c == '*') {
                if (curr.size() > 0) curr.pop_back();
            }
            else if (c == '#') curr.append(curr);
            else if (c == '%') reverse(curr.begin(), curr.end());
            else curr.push_back(c);
        }

        return curr;
    }
};