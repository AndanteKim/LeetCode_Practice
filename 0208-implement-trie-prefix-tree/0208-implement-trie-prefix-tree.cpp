class Trie {
private:
    struct TrieNode{
        TrieNode* children[26];
        bool isLeafNode;
    };
    TrieNode* root = new TrieNode();
public:
    Trie() {}
    
    TrieNode* getTrieNode(){
        TrieNode* node = new TrieNode();
        for (int i = 0; i < 26; ++i) node -> children[i] = NULL;
        node -> isLeafNode = false;
        return node;
    }
    
    void insert(string word) {
        if (search(word)) return;
        if (!root) root = getTrieNode();
        
        TrieNode* node = root;
        
        for (int i = 0; i < word.size(); ++i){
            int idx = word[i] - 'a';
            if (!node -> children[idx]){
                node -> children[idx] = getTrieNode();
            }
            node = node -> children[idx];
        }
        
        node -> isLeafNode = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        
        if (!root) return false;
        
        for (int i = 0; (i < word.size()) && node; ++i){
            int idx = word[i] - 'a';
            node = node -> children[idx];
        }
        
        if (node) return node -> isLeafNode;
        return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode* current_node = root;
        if (!root) return false;
        
        for (int i = 0; (i < prefix.size()) && current_node; ++i){
            int idx = prefix[i] - 'a';
            current_node = current_node -> children[idx];
        }
        
        return (current_node != NULL);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */