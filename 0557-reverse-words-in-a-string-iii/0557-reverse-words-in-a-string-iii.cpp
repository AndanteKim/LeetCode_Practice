class Solution {
public:
    string reverseWords(string s) {
        int lastSpaceIndex = -1, len = s.size();
        
        for (int strIndex = 0; strIndex <= len; ++strIndex){
            if (strIndex == len || s[strIndex] == ' '){
                int startIndex = lastSpaceIndex + 1;
                int endIndex = strIndex - 1;
                while (startIndex < endIndex){
                    swap(s[startIndex], s[endIndex]);
                    ++startIndex;
                    --endIndex;
                }
                lastSpaceIndex = strIndex;
            }   
        }
        
        return s;
    }
};