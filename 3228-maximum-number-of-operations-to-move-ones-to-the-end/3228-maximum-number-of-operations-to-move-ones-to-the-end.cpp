class Solution {
public:
    int maxOperations(string s) {
        int ans = 0, ones = 0, n = s.size();

        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') ++ones;
            else if (i + 1 == n || s[i + 1] == '1') ans += ones;
        }

        return ans;
    }
};