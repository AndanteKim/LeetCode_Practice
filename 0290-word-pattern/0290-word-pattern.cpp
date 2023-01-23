class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> map_char;
        unordered_map<string, char> map_word;
        stringstream ss(s);
        string word;
        vector<string> str;
        while (ss >> word)
            str.push_back(word);
        if (str.size() != pattern.size()) return false;
        
        for (int i = 0; i < pattern.size(); ++i){
            if (map_char.find(pattern[i]) == map_char.end()) {
                if (map_word.find(str[i]) != map_word.end()) return false;
                else{
                    map_char[pattern[i]] = str[i];
                    map_word[str[i]] = pattern[i];
                }
            }
            else{
                if (map_char[pattern[i]] != str[i]) return false;
            }
        }
        
        return true;
    }
};