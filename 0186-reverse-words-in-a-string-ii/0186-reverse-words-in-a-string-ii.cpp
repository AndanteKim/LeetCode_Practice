class Solution {
public:
    void reverse_each_word(vector<char> &s){
        int n = s.size();
        int start = 0, end = 0;
        while (start < n){
            while (end < n && s[end] != ' '){
                ++end;
            }
            reverse(s.begin() + start, s.begin() + end);
            start = end + 1;
            ++end;
        }
        
    }
    
    void reverseWords(vector<char>& s) {
        reverse(s.begin(), s.end());
        reverse_each_word(s);
    }
};