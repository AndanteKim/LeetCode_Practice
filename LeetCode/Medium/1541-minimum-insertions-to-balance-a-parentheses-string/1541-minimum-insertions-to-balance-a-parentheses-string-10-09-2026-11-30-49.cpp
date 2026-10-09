class Solution {
public:
    int minInsertions(string s) {
        int n = s.size(), i, left = 0, ans = 0;

        for (i = 0; i < n;) {
            if (s[i] == '(') {
                ++left;
                ++i;
            }
            else {
                if (left > 0) --left;
                else ++ans;

                if (i < n - 1 && s[i + 1] == ')') i += 2;
                else {
                    ++ans;
                    ++i;
                }
            }
        }

        cout << left << endl;
        ans += left * 2;
        return ans;
    }
};