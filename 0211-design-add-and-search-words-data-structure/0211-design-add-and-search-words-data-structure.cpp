struct TrieNode{
    bool end;
    vector<TrieNode*> children = vector<TrieNode*>(26, nullptr);  
};

class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for (const char& c : word){
            int index = c - 'a';
            if (!curr -> children[index]){
                curr -> children[index] = new TrieNode();
            }
            curr = curr -> children[index];
        }
        curr -> end = true;
    }
    
    bool pathSearch(string word, TrieNode* root, int index){
        if (index == word.size()) return root -> end;
        TrieNode* node = root;
        char c = word[index];
        
        int idx = c - 'a';
        if (c == '.'){
            for (int i = 0; i < 26; ++i){
                if (node -> children[i]){
                    bool search = pathSearch(word, node -> children[i], index + 1);
                    if (search) return true;
                }
            }
            return false;
        }
        else{
            if (!node -> children[idx]) return false;
            return pathSearch(word, node -> children[idx], index + 1);
        }
    }
    
    bool search(string word) {
        return pathSearch(word, root, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */