class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0, n = s.size();
        vector<int> lastPos(3, -1);

        for (int i = 0; i < n; ++i) {
            lastPos[s[i] - 97] = i;
            
            ans += 1 + *min_element(lastPos.begin(), lastPos.end());
        }

        return ans;
    }
};