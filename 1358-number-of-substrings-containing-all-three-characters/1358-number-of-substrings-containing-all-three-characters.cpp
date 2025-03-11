class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0, n = s.size();

        // Track last position of a, b, c
        vector<int> lastPos(3, -1);

        for (int pos = 0; pos < n; ++pos){
            // Update last position of current character
            lastPos[s[pos] - 97] = pos;

            // Add count of valid substrings ending at current position
            // If any character is missing, min will be -1
            // Else min gives leftmost required character position
            ans += 1 + *min_element(lastPos.begin(), lastPos.end());
        }

        return ans;
    }
};