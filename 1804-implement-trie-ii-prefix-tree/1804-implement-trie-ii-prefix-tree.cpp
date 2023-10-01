class TrieNode{
public:
    int startWords = 0, endWords = 0;
    TrieNode* links[26];
};


class Trie {
private:
    TrieNode *root = new TrieNode();
public:
    Trie() {}
    
    void insert(string word) {
        TrieNode *curr = root;
        
        for (char& c : word){
            int charIndex = c - 'a';
            if (!curr -> links[charIndex])
                curr -> links[charIndex] = new TrieNode();
            curr = curr -> links[charIndex];
            ++curr -> startWords;
        }
        ++curr-> endWords;
    }
    
    int countWordsEqualTo(string word) {
        TrieNode *curr = root;
        for (char& c : word){
            int charIndex = c - 'a';
            if (!curr -> links[charIndex])
                return 0;
            curr = curr -> links[charIndex]; 
        }
        return curr -> endWords;
    }
    
    int countWordsStartingWith(string prefix) {
        TrieNode *curr = root;
        for (char& c : prefix){
            int charIndex = c - 'a';
            if (!curr -> links[charIndex])
                return 0;
            curr = curr -> links[charIndex]; 
        }
        return curr -> startWords;
    }
    
    void erase(string word) {
        TrieNode *curr = root;
        
        for (char& c : word){
            int charIndex = c - 'a';
            
            curr = curr -> links[charIndex];
            --curr -> startWords;
        }
        --curr-> endWords;
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