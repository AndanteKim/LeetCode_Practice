class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;
        
        vector<int> word1Map(26, 0), word2Map(26, 0);
        int word1Bit = 0, word2Bit = 0;
        for (const char &c : word1){
            ++word1Map[c - 'a'];
            word1Bit = word1Bit | (1 << (c - 'a'));
        }
        
        for (const char &c : word2){
            ++word2Map[c - 'a'];
            word2Bit = word2Bit | (1 << (c - 'a'));
        }
        
        if (word1Bit != word2Bit) return false;
        sort(word1Map.begin(), word1Map.end());
        sort(word2Map.begin(), word2Map.end());
        
        for (int i = 0; i < 26; ++i) if (word1Map[i] != word2Map[i]) return false;
        return true;
    }
};