class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.empty())
            return true;
        
        int i = 0, length = s.size();
        
        for (char& c : t){
            if (c == s[i]){
                ++i;
                if (i == length)
                    return true;
            }
        }
        
        return false;
    }
};