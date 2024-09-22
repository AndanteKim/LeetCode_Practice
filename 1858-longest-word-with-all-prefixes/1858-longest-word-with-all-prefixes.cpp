class Trie{
private:
    struct TrieNode{
        bool isEnd = false;
        unordered_map<char, TrieNode*> children;
    };
    
    TrieNode* root;
    
    void deleteTrie(TrieNode* curr){
        if (!curr) return;
        for (auto& [c, _] : curr -> children)
            deleteTrie(curr -> children[c]);
        delete curr;
    }
    
public:
    Trie(){
        root = new TrieNode();
    }
    
    // Insert a word into the trie
    void insert(const string& s){
        TrieNode* curr = root;
        for (const char& c : s){
            if (!curr -> children.count(c))
                curr -> children[c] = new TrieNode();
            curr = curr -> children[c];
        }
        
        curr -> isEnd = true;
    }
    
    // Check if all prefixes of the word exists in the trie
    bool hasAllPrefixWords(const string& s) const{
        TrieNode* curr = root;
        
        for (const char& c : s){
            if (!curr -> children.count(c) || !curr -> children[c] -> isEnd)
                return false;
            curr = curr -> children[c];
        }
        
        return true;
    }
    
    // Destructor to free allocated memory
    ~Trie(){
        deleteTrie(root);
    }
};



class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie* trie = new Trie();
        
        // Insert all words into the trie
        for (const string& word : words)
            trie -> insert(word);
        
        string longestWord = "";
        
        // Check each word and update the longest valid word
        for (const string& word : words){
            if (trie -> hasAllPrefixWords(word)){
                if (word.size() > longestWord.size() || (word.size() == longestWord.size() && (longestWord.compare(word) > 0)))
                    longestWord = word;
            }
        }
        
        return longestWord;
    }
};