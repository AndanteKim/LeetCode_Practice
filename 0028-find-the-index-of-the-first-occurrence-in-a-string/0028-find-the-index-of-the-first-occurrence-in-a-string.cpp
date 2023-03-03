class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0, m = haystack.size(), n = needle.size();
        
        while (i <= m - n){
            if (haystack.substr(i, n) == needle) return i;
            ++i;
        }
        
        return -1;
    }
};