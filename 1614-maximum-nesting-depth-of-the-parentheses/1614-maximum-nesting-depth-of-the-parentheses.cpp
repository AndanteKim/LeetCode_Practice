class Solution {
public:
    int maxDepth(string s) {
        int ans = 0, cnt = 0;

        for (const char& c : s) {
            if (c == '(') ++cnt;
            else if (c == ')') --cnt;
            ans = max(ans, cnt);
        }

        return ans;
    }
};