class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> chars_word1(26, 0), chars_word2(26, 0);
        
        for (const char& c: word1) ++chars_word1[c - 'a'];
        for (const char& c: word2) ++chars_word2[c - 'a'];
        for (int i = 0; i < 26; ++i) if ((chars_word1[i] > 0 && chars_word2[i] == 0) || (chars_word1[i] == 0 && chars_word2[i] > 0)) return false;
        sort(chars_word1.begin(), chars_word1.end());
        sort(chars_word2.begin(), chars_word2.end());
        
        return chars_word1 == chars_word2;
    }
};