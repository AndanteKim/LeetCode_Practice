class Solution {
public:
    string reverseVowels(string s) {
        int i = 0, j = s.size() - 1;
        unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u',\
                                   'A', 'E', 'I', 'O', 'U'\
                                   };
        
        while (i < j){
            if (vowels.find(s[i]) == vowels.end()) ++i;
            if (vowels.find(s[j]) == vowels.end()) --j;
            
            if (vowels.find(s[i]) != vowels.end() && vowels.find(s[j]) != vowels.end()){
                swap(s[i], s[j]);
                ++i;
                --j;
            }
        }
        
        return s;
    }
};