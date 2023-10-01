struct TrieNode{
    int wordCount = 0, count = 0;
    unordered_map<char, TrieNode*> children;
    TrieNode(){}
};


class Trie {
private:
    TrieNode* root = new TrieNode();
    
public:
    Trie() {}
    
    void insert(string word) {
        TrieNode* curr = root;
        for (char& c : word){
            if (curr -> children.find(c) == curr -> children.end())
                curr -> children[c] = new TrieNode();
            ++curr -> children[c] -> count;
            curr = curr -> children[c];
        }
        ++curr -> wordCount;
    }
    
    int countWordsEqualTo(string word) {
        TrieNode *curr = root;
        for (char& c : word){
            if (curr -> children.find(c) == curr -> children.end())
                return 0;
            curr = curr -> children[c];
        }
        return curr -> wordCount;
    }
    
    int countWordsStartingWith(string prefix) {
        TrieNode *curr = root;
        for (char& c : prefix){
            if (curr -> children.find(c) == curr -> children.end())
                return 0;
            curr = curr -> children[c];
        }
        return curr -> count;
    }
    
    void erase(string word) {
        TrieNode *curr = root;
        for (char& c : word){
            if (curr -> children.find(c) == curr -> children.end())
                return;
            curr = curr -> children[c];
        }
        
        curr = root;
        for (char& c : word){
            --curr -> children[c] -> count;
            curr = curr -> children[c];
        }
        if (curr -> wordCount == 0) return;
        --curr -> wordCount;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */