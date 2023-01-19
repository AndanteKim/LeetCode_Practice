class Solution {
public:
    string reverseWords(string s) {
        int lastSpaceIndex = -1, len = s.size();
        string result;
        for (int strIndex = 0; strIndex < len; ++strIndex){
            if (strIndex == len - 1 || s[strIndex] == ' '){
                int reverseStrIndex = (strIndex == len - 1)? strIndex : strIndex - 1;
                for (; reverseStrIndex > lastSpaceIndex; --reverseStrIndex) result += s[reverseStrIndex];
                if (strIndex != len - 1) result += ' ';
                lastSpaceIndex = strIndex;
            }   
        }
        
        return result;
    }
};