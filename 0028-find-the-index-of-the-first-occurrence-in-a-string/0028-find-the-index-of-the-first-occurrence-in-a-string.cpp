class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = needle.size(), n = haystack.size();
        
        if (n < m) return -1;
        
        vector<int> longest_border(m, 0);
        
        int prev = 0, i = 1;
        
        while (i < m){
            if (needle[i] == needle[prev]){
                ++prev;
                longest_border[i] = prev;
                ++i;
            }
            else{
                if (prev == 0) {
                    longest_border[i] = 0;
                    ++i;
                }
                else prev = longest_border[prev - 1];
            }
        }
        
        int haystack_pointer = 0, needle_pointer = 0;
        
        while (haystack_pointer < n){
            if (haystack[haystack_pointer] == needle[needle_pointer]){
                ++needle_pointer;
                ++haystack_pointer;
                if (needle_pointer == m) return haystack_pointer - m;
            }
            else{
                if (needle_pointer == 0) ++haystack_pointer;
                else needle_pointer = longest_border[needle_pointer - 1];
            }
        }
        return -1;
    }
};