class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string, int> map_index;
        stringstream ss(s);
        string word;
        vector<string> str;
        while (ss >> word)
            str.push_back(word);
        if (str.size() != pattern.size()) return false;
        
        for (int i = 0; i < pattern.size(); ++i){
            string char_key = "char_";
            char_key.push_back(pattern[i]);
            string char_word = "word_" + str[i];
            
            if (map_index.find(char_key) == map_index.end()) map_index[char_key] = i;
            if (map_index.find(char_word) == map_index.end()) map_index[char_word] = i;
            
            if (map_index[char_key] != map_index[char_word]) return false;
        }
        
        return true;
    }
};