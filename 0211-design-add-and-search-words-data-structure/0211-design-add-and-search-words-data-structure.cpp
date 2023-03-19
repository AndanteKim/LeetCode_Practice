class WordDictionary {
    unordered_map<int, vector<string>> dict;
    
public:
    WordDictionary() {}
    
    void addWord(string word) {
        dict[word.size()].push_back(word);
    }
    
    bool search(string word) {
        int m = word.size();
        for (const string& dict_word : dict[m]){
            int i = 0;
            while (i < m && (dict_word[i] == word[i] || word[i] == '.')) ++i;
            if (i == m) return true;
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */