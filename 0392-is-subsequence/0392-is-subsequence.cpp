class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0, len_s = s.size(), len_t = t.size();
        
        while (i < len_s && j < len_t){
            if (s[i] == t[j]) {
                ++i; ++j;
            }
            else ++j;
        }
        
        return i == len_s? true : false;
    }
};