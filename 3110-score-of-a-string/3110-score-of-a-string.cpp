class Solution {
public:
    int scoreOfString(string s) {
        int ans = 0, n = s.size();
        
        for (int i = 1; i < n; ++i)
            ans += abs(s[i - 1] - s[i]);
        
        return ans;
    }
};