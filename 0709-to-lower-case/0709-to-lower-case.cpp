class Solution {
public:
    string toLowerCase(string s) {
        unordered_map<char, char> c_low{{'A','a'}, {'B', 'b'}, {'C', 'c'}, {'D', 'd'}, {'E', 'e'}, {'F', 'f'}, {'G', 'g'}
                                    , {'H', 'h'}, {'I', 'i'}, {'J', 'j'}, {'K', 'k'}, {'L', 'l'}, {'M', 'm'}, {'N', 'n'}\
                                    , {'O', 'o'}, {'P', 'p'}, {'Q', 'q'}, {'R', 'r'}, {'S', 's'}, {'T', 't'}, {'U', 'u'}\
                                          , {'V', 'v'}, {'W', 'w'}, {'X', 'x'}, {'Y', 'y'}, {'Z', 'z'}};
        
        for (int i = 0; i < s.size(); ++i){
            if (s[i] >= 'A' && s[i] <= 'Z') s[i] = c_low[s[i]];
        }
        return s;
    }
};