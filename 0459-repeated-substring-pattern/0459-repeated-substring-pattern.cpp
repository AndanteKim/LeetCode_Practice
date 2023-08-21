class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t = s + s;
        int n = t.size();
        
        if (t.substr(1, n - 2).find(s) != -1) return true;
        return false;
    }
};