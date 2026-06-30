class Solution {
public:
    int numberOfSubstrings(string s) {
        // Track the last position of a, b, c
        int ans = 0, n = s.size();
        vector<int> lastPos(3, -1);

        for (int i = 0; i < n; ++i) {
            // Update the last position of current character
            lastPos[s[i] - 97] = i;
            
            // Add count of valid substrings ending at current position
            ans += 1 + *min_element(lastPos.begin(), lastPos.end());
        }

        return ans;
    }
};