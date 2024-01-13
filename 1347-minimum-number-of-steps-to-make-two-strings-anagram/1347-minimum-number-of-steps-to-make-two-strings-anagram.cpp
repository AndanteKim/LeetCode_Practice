class Solution {
public:
    int minSteps(string s, string t) {
        int n = s.size(), ans = 0;
        vector<int> sChars(26), tChars(26);
        
        for (int i = 0; i < n; ++i){
            ++sChars[s[i] - 97];
            ++tChars[t[i] - 97];
        }
        
        for (int i = 0; i < 26; ++i){
            ans += abs(sChars[i] - tChars[i]);
        }
        
        return ans >> 1;
    }
};