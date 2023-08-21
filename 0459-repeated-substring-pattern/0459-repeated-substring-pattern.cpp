class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string subStr = "";
        int n = s.size();
        for (int i = 0; i < n - 1; ++i){
            subStr += s[i];
            string repeat = "";
            for (int j = 0; j < n / subStr.size(); ++j) repeat += subStr;
            
            if (repeat == s) return true;
        }
        
        return false;
    }
};