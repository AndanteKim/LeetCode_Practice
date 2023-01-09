class Solution {
public:
    char findTheDifference(string s, string t) {
        int ch = 0;
        
        for(const auto &char_ : s) ch ^= (int)(char_ - '0');
        
        for(const auto &char_ : t) ch ^= (int)(char_ - '0');
        return (char)(ch+48);
    }
};